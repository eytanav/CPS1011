#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    int A3 = 1000, A4 = 1000, A5 = 1000, A3_Chosen, A4_Chosen, A5_Chosen;
    _Bool isValid = false;

    do
    {
        printf("Input the amount of A3 papers you would like to order:\n");
        scanf("%i", &A3_Chosen);
        if (A3_Chosen <= 1000)
            isValid = true;
    } while (!isValid);

    isValid = false;
    do
    {
        printf("Input the amount of A4 papers you would like to order:\n");
        scanf("%i", &A4_Chosen);
        if (A4_Chosen <= 1000)
            isValid = true;
    } while (!isValid);

    isValid = false;
    do
    {
        printf("Input the amount of A5 papers you would like to order:\n");
        scanf("%i", &A5_Chosen);
        if (A5_Chosen <= 1000)
            isValid = true;
    } while (!isValid);

    A3 -= A3_Chosen;
    A4 -= A4_Chosen;
    A5 -= A5_Chosen;

    printf("A3 Stock\nOrder Amount: %i \nUpdated Stock: %i\n\n", A3_Chosen, A3);
    printf("A4 Stock\nOrder Amount: %i \nUpdated Stock: %i\n\n", A4_Chosen, A4);
    printf("A5 Stock\nOrder Amount: %i \nUpdated Stock: %i", A5_Chosen, A5);

    return 0;
}