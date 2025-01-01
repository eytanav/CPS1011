#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRINGS 100
#define MAX_LENGTH 100

int main()
{
    char strings[MAX_STRINGS][MAX_LENGTH];
    char suffix[MAX_LENGTH];
    int indices[MAX_STRINGS];
    int count = 0, i, num_indices = 0;

    printf("Enter strings one by one (type '#' to finish):\n");
    while (count < MAX_STRINGS)
    {
        printf("Enter string %d: ", count + 1);
        fgets(strings[count], MAX_LENGTH, stdin);

        strings[count][strcspn(strings[count], "\n")] = '\0';

        if (strcmp(strings[count], "#") == 0)
        {
            break;
        }
        count++;
    }

    printf("\nEnter a suffix to append: ");
    fgets(suffix, MAX_LENGTH, stdin);
    suffix[strcspn(suffix, "\n")] = '\0';

    printf("\nYou've entered the following strings:\n");
    for (i = 0; i < count; i++)
    {
        printf("%d. %s\n", i + 1, strings[i]);
    }

    printf("\nEnter the indices of the strings to modify (separated by spaces): ");

    char input[MAX_LENGTH];
    fgets(input, MAX_LENGTH, stdin);

    char *token = strtok(input, " ");
    while (token != NULL && num_indices < MAX_STRINGS)
    {
        indices[num_indices] = atoi(token) - 1;
        num_indices++;
        token = strtok(NULL, " ");
    }

    for (i = 0; i < num_indices; i++)
    {
        int index = indices[i];
        if (index >= 0 && index < count)
        {
            strcat(strings[index], suffix);
        }
        else
        {
            printf("Index %d is out of range.\n", index + 1);
        }
    }

    printf("\nModified strings:\n");
    for (i = 0; i < count; i++)
    {
        printf("%d. %s\n", i + 1, strings[i]);
    }

    return 0;
}