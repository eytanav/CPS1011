#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

int is_whole_word(const char *text, int position, const char *word, int word_length)
{
    if (position > 0 && isalnum(text[position - 1]))
    {
        return 0;
    }

    if (position + word_length < strlen(text) && isalnum(text[position + word_length]))
    {
        return 0;
    }

    return 1;
}

void search_and_replace(const char *file_path, const char *search_word, const char *replace_word)
{
    FILE *file = fopen(file_path, "r");
    if (!file)
    {
        fprintf(stderr, "Error: Cannot open file %s\n", file_path);
        return;
    }

    char *buffer = malloc(BUFFER_SIZE);
    if (!buffer)
    {
        fprintf(stderr, "Error: Memory allocation failed\n");
        fclose(file);
        return;
    }

    size_t buffer_size = 0;
    size_t search_length = strlen(search_word);
    size_t replace_length = strlen(replace_word);

    while (!feof(file))
    {
        char chunk[BUFFER_SIZE];
        size_t bytes_read = fread(chunk, 1, BUFFER_SIZE, file);
        buffer = realloc(buffer, buffer_size + bytes_read + 1);
        if (!buffer)
        {
            fprintf(stderr, "Error: Memory reallocation failed\n");
            fclose(file);
            return;
        }
        memcpy(buffer + buffer_size, chunk, bytes_read);
        buffer_size += bytes_read;
        buffer[buffer_size] = '\0';
    }

    fclose(file);

    char *result = malloc(buffer_size * 2);
    if (!result)
    {
        fprintf(stderr, "Error: Memory allocation failed\n");
        free(buffer);
        return;
    }

    char *current = buffer;
    char *output = result;
    size_t remaining_space = buffer_size * 2;

    while ((current = strstr(current, search_word)) != NULL)
    {
        if (is_whole_word(buffer, current - buffer, search_word, search_length))
        {
            size_t prefix_length = current - buffer;
            if (prefix_length + replace_length >= remaining_space)
            {
                fprintf(stderr, "Error: Buffer overflow risk detected\n");
                free(buffer);
                free(result);
                return;
            }

            memcpy(output, buffer, prefix_length);
            output += prefix_length;
            remaining_space -= prefix_length;

            memcpy(output, replace_word, replace_length);
            output += replace_length;
            remaining_space -= replace_length;

            current += search_length;
            buffer = current;
        }
        else
        {
            *output++ = *current++;
            remaining_space--;
        }
    }

    strncpy(output, buffer, remaining_space - 1);
    output[remaining_space - 1] = '\0';

    file = fopen(file_path, "w");
    if (!file)
    {
        fprintf(stderr, "Error: Cannot write to file %s\n", file_path);
        free(buffer);
        free(result);
        return;
    }

    fwrite(result, 1, strlen(result), file);

    fclose(file);

    free(result);

    printf("Replacement finished!\n");
}

int main()
{
    char file_path[BUFFER_SIZE];
    char search_word[BUFFER_SIZE];
    char replace_word[BUFFER_SIZE];

    printf("Enter the path to the text file: ");
    fgets(file_path, BUFFER_SIZE, stdin);
    file_path[strcspn(file_path, "\n")] = '\0';

    printf("Enter the word to search for: ");
    fgets(search_word, BUFFER_SIZE, stdin);
    search_word[strcspn(search_word, "\n")] = '\0';

    printf("Enter the word to replace with: ");
    fgets(replace_word, BUFFER_SIZE, stdin);
    replace_word[strcspn(replace_word, "\n")] = '\0';

    search_and_replace(file_path, search_word, replace_word);

    return 0;
}
