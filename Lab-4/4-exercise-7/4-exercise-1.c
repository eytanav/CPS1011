#include <stdio.h>
#include "4-exercise-1.h"

long fact(int n)
{
    long ans = 1;
    for (; n > 1; n--)
    {
        ans *= n;
    }
    return ans;
}

long rfact(int n)
{
    return n > 0 ? n * rfact(n - 1) : 1;
}

void runExercise1()
{
    int n;
    printf("Enter a number for factorial calculation: ");
    scanf("%d", &n);
    printf("Iterative factorial of %d: %ld\n", n, fact(n));
    printf("Recursive factorial of %d: %ld\n", n, rfact(n));
}
