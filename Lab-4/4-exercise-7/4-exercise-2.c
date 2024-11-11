#include <stdio.h>
#include "4-exercise-2.h"
// less readable as it requires more variables and lines to compute
// more efficient in memory usage since space complexity is O(1) since no additional frames are created on the stack
long iterfib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        long n1 = 0, n2 = 1, n3;
        for (int i = 2; i <= n; i++)
        {
            n3 = n2 + n1;
            n1 = n2;
            n2 = n3;
        }
        return n3;
    }
}

// much more readable as it requires less lines and the function is straightforward to understand
// much less memory efficient as the space complexity is O(n)
long recurfib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return recurfib(n - 1) + recurfib(n - 2);
    }
}

void runExercise2()
{
    int n;
    printf("Input the nth number in the fibonacci sequence to display: ");
    scanf("%d", &n);

    printf("\nF(%d) = %ld", n, iterfib(n));

    printf("\nF(%d) = %ld", n, recurfib(n));
}