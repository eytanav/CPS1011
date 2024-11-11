#include <stdio.h>
#include "4-exercise-3.h"
// less readable
// O(1), as only one stack frame is used
// therefore more efficient
int iterGCD(int x, int y)
{
    int temp;
    while (y != 0)
    {
        if (y == 0)
        {
            return x;
        }
        else
        {
            temp = y;
            y = x % y;
            x = temp;
        }
    }
    return x;
}

// more readable, very elegant expression
// O(log(min(x,y)))
// less efficient memory usage
int recurGCD(int x, int y)
{
    if (y == 0)
    {
        return x;
    }
    else
    {
        recurGCD(y, x % y);
    }
}

void runExercise3()
{
    int x, y;

    printf("Input an integer: ");
    scanf("%d", &x);
    printf("Input another integer: ");
    scanf("%d", &y);

    printf("The greatest common divisor of %d and %d is: %d\n", x, y, recurGCD(x, y));
}