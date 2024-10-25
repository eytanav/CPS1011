#include <stdio.h>
#include <string.h>

void reverse(char *str)
{
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++)
    {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int main()
{
    char word1[100], word2[100], word3[100];

    printf("Enter the first word: ");
    scanf("%s", word1);

    printf("Enter the second word: ");
    scanf("%s", word2);

    printf("Enter the third word: ");
    scanf("%s", word3);

    reverse(word1);
    reverse(word2);
    reverse(word3);

    printf("\nReversed words:\n");
    printf("First word: %s\n", word1);
    printf("Second word: %s\n", word2);
    printf("Third word: %s\n", word3);

    return 0;
}