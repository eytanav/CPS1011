#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_TEXT_LENGTH 1000

// Function to check if a string is purely punctuation
int is_pure_punctuation(const char *word)
{
    for (int i = 0; i < strlen(word); i++)
    {
        if (!ispunct(word[i]))
        {
            return 0; // Not purely punctuation
        }
    }
    return 1; // Purely punctuation
}

// Function to process each word and check for errors
void process_word(const char *word, int *error_count)
{
    // Skip processing if the word is purely punctuation
    if (is_pure_punctuation(word))
    {
        return;
    }

    int length = strlen(word);
    int has_hyphen = strchr(word, '-') != NULL;
    int has_uppercase_beyond_first = 0;
    int starts_with_non_alpha = !isalpha(word[0]);

    // Check if there are uppercase letters beyond the first character
    for (int i = 1; i < length; i++)
    {
        if (isupper(word[i]))
        {
            has_uppercase_beyond_first = 1;
            break;
        }
    }

    // Check each condition and print warnings if necessary
    if (length > 10 && !has_hyphen)
    {
        printf("Warning: '%s' is longer than 10 characters without a hyphen.\n", word);
        (*error_count)++;
    }
    if (has_uppercase_beyond_first)
    {
        printf("Warning: '%s' contains uppercase letters beyond the first character.\n", word);
        (*error_count)++;
    }
    if (starts_with_non_alpha)
    {
        printf("Warning: '%s' starts with a non-alphabetic character.\n", word);
        (*error_count)++;
    }
}

// Function to check for punctuation preceded by space and repeated spaces
void check_for_spacing_issues(const char *text, int *error_count)
{
    int length = strlen(text);
    int previous_was_space = 0;

    for (int i = 0; i < length; i++)
    {
        if (text[i] == ' ')
        {
            // Check for repeated spaces
            if (previous_was_space)
            {
                printf("Warning: Repeated space found at position %d.\n", i);
                (*error_count)++;
            }
            previous_was_space = 1;
        }
        else if (ispunct(text[i]) && previous_was_space)
        {
            // Check for punctuation preceded by a space
            printf("Warning: Punctuation '%c' preceded by space at position %d.\n", text[i], i);
            (*error_count)++;
            previous_was_space = 0;
        }
        else
        {
            previous_was_space = 0;
        }
    }
}

int main()
{
    char word[MAX_WORD_LENGTH];
    int error_count = 0;
    char text[MAX_TEXT_LENGTH];

    printf("Enter text (press Enter to finish):\n");

    // Read the entire line of text for spacing issues check
    if (fgets(text, MAX_TEXT_LENGTH, stdin) != NULL)
    {
        char *ptr = text;

        // Process each word in the text
        while (sscanf(ptr, "%s", word) == 1)
        {
            process_word(word, &error_count); // Process the word for errors
            ptr += strlen(word);              // Move the pointer past the word

            // Move past any spaces between words
            while (*ptr == ' ')
                ptr++;
        }

        // Check the entire text for spacing issues
        check_for_spacing_issues(text, &error_count);
    }

    // Display the total number of errors
    if (error_count == 0)
    {
        printf("No errors found\n");
    }
    else if (error_count == 1)
    {
        printf("1 error found\n");
    }
    else
    {
        printf("%d errors found\n", error_count);
    }

    return 0;
}
