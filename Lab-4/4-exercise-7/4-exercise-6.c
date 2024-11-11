#include <stdio.h>
#include <math.h>
#include "4-exercise-6.h"

void applyCeil(double *x)
{
    *x = ceil(*x);
}

void applyFloor(double *x)
{
    *x = floor(*x);
}

void customApplyCeil(double *x)
{
    int intPart = (int)(*x); // Get the integer part of x

    if (*x > intPart)
    {
        // If x is positive and has a fractional part, add 1
        *x = intPart + 1;
    }
    else
    {
        // Otherwise, x is already at or below its ceiling
        *x = intPart;
    }
}

void customApplyFloor(double *x)
{
    int intPart = (int)(*x); // Get the integer part of x

    if (*x < intPart)
    {
        // If x is negative and has a fractional part, subtract 1
        *x = intPart - 1;
    }
    else
    {
        // Otherwise, x is already at or above its floor
        *x = intPart;
    }
}

void runExercise6()
{
    double num1 = 3.7, num2 = -2.3;

    applyCeil(&num1);
    printf("Ceiling: %.1f\n", num1);

    applyFloor(&num2);
    printf("Floor: %.1f\n", num2);

    customApplyCeil(&num1);
    printf("Custom Ceiling: %.1f\n", num1);

    customApplyFloor(&num2);
    printf("Custom Floor: %.1f\n", num2);
}
