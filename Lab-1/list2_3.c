/* two_func.c -- a program using two functions in one file */

#include <stdio.h>

void butler(char *name); /* ISO/ANSI C function prototyping */

int main(void)

{
    char name[100];
    printf("Input your name\n");
    scanf("%99s", name);
    printf("I will summon the butler function.\n");

    butler(name);

    printf("Yes. Bring me some tea and writeable CD-ROMS.\n");

    return 0;
}

void butler(char *name) /* start of function definition */
{

    printf("You rang, %s?\n", name);
}
