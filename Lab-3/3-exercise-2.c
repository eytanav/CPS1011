#include <stdio.h>

int main(void)
{

    unsigned long long fact = 1;
    int n;
    printf("Input a number to compute its factorial: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    printf("The factorial of %d is: %llu", n, fact);

    return 0;
}