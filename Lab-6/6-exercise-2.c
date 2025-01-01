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
    FILE *input_file = fopen(file_path, "r");
    if (!input_file)
    {
        fprintf(stderr, "Error: Cannot open file %s\n", file_path);
        return;
    }

    FILE *output_file = tmpfile();
    if (!output_file)
    {
        fprintf(stderr, "Error: Cannot create temporary file\n");
        fclose(input_file);
        return;
    }

    char chunk[BUFFER_SIZE];
    size_t search_length = strlen(search_word);
    size_t replace_length = strlen(replace_word);

    while (fgets(chunk, sizeof(chunk), input_file))
    {
        char *current = chunk;
        char *start = chunk;

        while ((current = strstr(current, search_word)) != NULL)
        {
            if (is_whole_word(chunk, current - chunk, search_word, search_length))
            {
                fwrite(start, 1, current - start, output_file);

                fwrite(replace_word, 1, replace_length, output_file);

                current += search_length;
                start = current;
            }
            else
            {
                fputc(*current++, output_file);
            }
        }

        fputs(start, output_file);
    }

    fclose(input_file);

    rewind(output_file);

    FILE *final_file = fopen(file_path, "w");
    if (!final_file)
    {
        fprintf(stderr, "Error: Cannot open file %s for writing\n", file_path);
        fclose(output_file);
        return;
    }

    char final_chunk[BUFFER_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(final_chunk, 1, sizeof(final_chunk), output_file)) > 0)
    {
        fwrite(final_chunk, 1, bytes_read, final_file);
    }

    fclose(final_file);
    fclose(output_file);

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
