#include <stdio.h>

int main()
{
    int n = 0;
    unsigned long long factorial = 1; // handles massive factorials
    printf("Input a number 'n' to find its factorial 'n!':\n");
    scanf("%d", &n);

    if (n < 0)
        printf("Factorial is not valid for negative numbers");
    // Note: n == 0 is covered as factorial already equals 1 (0! = 1)
    else
    {
        for (int i = 1; i <= n; i++)
        {
            factorial *= i;
        }
        printf("Factorial of %d is: %llu", n, factorial);
    }
    return 0;
}