#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Error: This program requires exactly two numeric arguments.\n");
        printf("Usage: ./add_numbers <num1> <num2>\n");
        return 1;
    }

    char *endptr1, *endptr2;
    double num1 = strtod(argv[1], &endptr1);
    double num2 = strtod(argv[2], &endptr2);

    if (*endptr1 != '\0' || *endptr2 != '\0')
    {
        printf("Error: Both arguments must be numeric values.\n");
        return 1;
    }

    double result = num1 + num2;
    printf("The sum of %.2f and %.2f is %.2f\n", num1, num2, result);

    return 0;
}
