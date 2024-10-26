#include <stdio.h>

#define DAYS_IN_WEEK 7
#define TOTAL_ENTRIES 10 // Number of user inputs

int main()
{
    int days[TOTAL_ENTRIES];
    int weeks, remaining_days;

    printf("Enter %d values representing days:\n", TOTAL_ENTRIES);

    // Get 10 days from the user
    for (int i = 0; i < TOTAL_ENTRIES; i++)
    {
        printf("Days %d: ", i + 1);
        scanf("%d", &days[i]);
    }

    printf("\nConversion to weeks and days:\n\n");

    // Convert each day entry to weeks and days
    for (int i = 0; i < TOTAL_ENTRIES; i++)
    {
        weeks = days[i] / DAYS_IN_WEEK;
        remaining_days = days[i] % DAYS_IN_WEEK;
        printf("%d days is %d weeks and %d days\n", days[i], weeks, remaining_days);
    }

    return 0;
}
