#include <stdio.h>
int main()
{
    int feet, fathoms; // The symbolic identifiers are feet and fathoms, and this is the declaration of the variables

    fathoms = 2; // fathoms is the lvalue (memory address), whilst 2 is the rvalue (actual content)

    feet = 6 * fathoms; // feet is the lvalue, 6*fathoms is the rvalue

    printf("There are %d feet in %d fathoms!\n", feet, fathoms);

    printf("Yes, I said %d feet!\n", 6 * fathoms);
}
