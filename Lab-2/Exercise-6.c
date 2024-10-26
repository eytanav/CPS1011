#include <stdio.h>

#define TOTAL_CONVERSIONS 10      // Number of conversions to perform
#define EURO_CONVERSION_RATE 0.93 // Exchange rate for dollars to euros (24th October 2024)

int main()
{
    double dollars[TOTAL_CONVERSIONS];
    double euros;

    printf("Enter %d dollar amounts to convert to euros:\n", TOTAL_CONVERSIONS);

    // Collect 10 dollar amounts from the user
    for (int i = 0; i < TOTAL_CONVERSIONS; i++)
    {
        printf("Dollar amount %d: $", i + 1);
        scanf("%lf", &dollars[i]);
    }

    printf("\nDollar to Euro conversions:\n");

    // Convert each dollar amount to euros and display the result
    for (int i = 0; i < TOTAL_CONVERSIONS; i++)
    {
        euros = dollars[i] * EURO_CONVERSION_RATE;
        printf("$%.2f is €%.2f\n", dollars[i], euros);
    }

    return 0;
}
