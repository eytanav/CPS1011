#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "4-exercise-5.h"

int validateInput(const char *str)
{

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isdigit(str[i]))
        {
            return 0;
        }
    }
    return 1;
}

int mostFrequentCharacter(const char *str)
{
    int frequency[256] = {0};
    int maxFreq = 0;
    char mostFreqChar = str[0];

    for (int i = 0; str[i] != '\0'; i++)
    {
        frequency[(unsigned char)str[i]]++;
        // Update most frequent character
        if (frequency[(unsigned char)str[i]] > maxFreq)
        {
            maxFreq = frequency[(unsigned char)str[i]];
            mostFreqChar = str[i];
        }
    }

    return mostFreqChar;
}

void analyzeString(const char *str)
{

    if (!validateInput(str))
    {
        printf("Invalid input: String contains numeric characters.\n");
        return;
    }

    int length = strlen(str);
    char firstChar = str[0];
    char mostFreqChar = mostFrequentCharacter(str);

    printf("Input is valid.\n");
    printf("Input length: %d\n", length);
    printf("Input's first character: %c\n", firstChar);
    printf("Input's most frequent character: %c\n", mostFreqChar);
}

void runExercise5()
{
    char input[100];

    printf("Enter strings (no numeric characters allowed), or type 'exit' to stop:\n");
    while (1)
    {
        printf("Enter a string: ");
        scanf("%99s", input);

        if (strcmp(input, "exit") == 0)
        {
            break;
        }

        analyzeString(input);
    }
}
