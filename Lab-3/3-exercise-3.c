#include <stdio.h>
#define PIN_CODE 1234
int main(void)
{

    int correct = 0;
    int count = 1;
    int guess = 0;
    while (correct == 0 && count < 6)
    {
        printf("Guess the pin code (Attempt %d): ", count);
        scanf("%d", &guess);
        if (guess == PIN_CODE)
            correct = 1;
        else
            printf("Incorrect pin code!\n");
        count++;
    }

    if (correct == 1)
        printf("Successfully logged in!");
    else
        printf("You have been locked out due to multiple incorrect login attempts");

    return 0;
}