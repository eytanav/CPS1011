#include <stdio.h>

double calc_tax(int first_taxed, unsigned int gross_pay)
{
    double tax_total = 0;

    if (gross_pay <= first_taxed)
    {
        tax_total = gross_pay * 0.18;
    }
    else if (gross_pay <= (first_taxed + 8000))
    {
        tax_total = (first_taxed * 0.18) + ((gross_pay - first_taxed) * 0.2);
    }
    else
    {
        tax_total = (first_taxed * 0.18) + (8000 * 0.2) + ((gross_pay - (first_taxed + 8000)) * 0.25);
    }

    return tax_total;
}

int main(void)
{
    unsigned int gross_pay;
    double total_tax, net_pay;
    int valid = 0, in_ICT, collect_eqp, first_taxed = 10000;

    printf("Input the amount of money you make: ");
    scanf("%u", &gross_pay);

    while (valid == 0)
    {
        printf("Do you collect old electronic equipment? (1-Yes | 2-No)\n");
        scanf("%d", &collect_eqp);
        if (collect_eqp == 1)
        {
            valid = 1;
            first_taxed = 15000;
        }
        else if (collect_eqp == 2)
        {
            valid = 1;
        }
        else
        {
            printf("Invalid number input");
        }
    }

    total_tax = calc_tax(first_taxed, gross_pay);
    valid = 0;
    while (valid == 0)
    {
        printf("\nDo you work at in the ICT industry? (1-Yes | 2-No)\n");
        scanf("%d", &in_ICT);
        if (in_ICT == 1)
        {
            net_pay = gross_pay - (total_tax * 0.95);
            valid = 1;
        }
        else if (in_ICT == 2)
        {
            net_pay = gross_pay - total_tax;
            valid = 1;
        }
        else
        {
            printf("Invalid number input");
        }
    }

    printf("Gross Pay: €%u\nNet Pay: €%.2lf\n", gross_pay, net_pay);
    return 0;
}