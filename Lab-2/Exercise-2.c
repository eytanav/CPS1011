#include <stdio.h>

int main()
{
    float weight;
    int value;
    printf("Enter your weight in pounds: \n");
    scanf("%f", &weight);
    // Platinum is $1770 / pound
    // 14.5 troy ounces in 1 pound
    value = 1770.0 * weight * 14.5;
    printf("Your weight in platinum costs $%.4f. \n", value);

    printf("Your number in octal: %o\n", value);
    printf("Your number in hexadecimal: %x\n", value);
}
