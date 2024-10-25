#include <stdio.h>

int main()
{
    int input;
    char character;

    printf("Enter an integer: ");
    scanf("%d", &input);

    character = (char)input;

    printf("The character in ASCII is: %c\n", character);
}