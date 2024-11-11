#include <stdio.h>
#include <string.h>
#include "4-exercise-4.h"
void decimalToHex(int n)
{
    // Array to map remainder values to hexadecimal characters
    const char hexDigits[] = "0123456789ABCDEF";

    // Base case: when n is 0, do nothing (to avoid extra 0s at the beginning)
    if (n == 0)
    {
        return;
    }

    // Recursive case: print the more significant digits first
    decimalToHex(n / 16);

    // Print the current hexadecimal digit
    printf("%c", hexDigits[n % 16]);
}

void reverseString(char str[], int start, int end)
{
    // Base case: if start index >= end index, reverse complete
    if (start >= end)
    {
        return;
    }

    // Swap the characters at start and end indices
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursive call for the inner substring
    reverseString(str, start + 1, end - 1);
}

void runExercise4()
{
    int number = 255;
    if (number == 0)
    {
        // Special case for 0, as our function does not handle printing the initial 0
        printf("0");
    }
    else
    {
        decimalToHex(number);
    }
    printf("\n");

    char text[] = "hello";
    reverseString(text, 0, strlen(text) - 1);
    printf("Reversed string: %s\n", text);
}
