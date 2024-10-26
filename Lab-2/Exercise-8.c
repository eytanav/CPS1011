#include <stdio.h>
#include <math.h>

double riemann_zeta(double s, int terms)
{
    double sum = 0.0;

    for (int n = 1; n <= terms; n++)
    {
        sum += 1 / pow(n, s);
    }
    return sum;
}
int main()
{
    double s;
    int terms;

    printf("Input the 's' in the Riemann zeta function (must be > 1): ");
    scanf("%lf", &s);

    if (s <= 1)
    {
        printf("The value of s must be greater than 1.\n");
    }

    printf("Enter the number of terms to approximate infinity: ");
    scanf("%d", &terms);

    double result = riemann_zeta(s, terms);
    printf("Approximation of the Riemann zeta function ζ(%lf) with %d terms = %lf\n", s, terms, result);
    return 0;
}