#include <stdio.h>
#include <string.h>

#define NLEN 30

typedef char string_t[NLEN];
typedef struct
{
    string_t fname;
    string_t lname;
    int letters;
} name_t;

name_t update_info(name_t info)
{
    info.letters = strlen(info.fname) + strlen(info.lname);
    return info;
}

int main(void)
{
    name_t person = {"Neville", "Grech", 0};
    person = update_info(person);

    printf("%s %s, your name contains %d letters.\n", person.fname, person.lname, person.letters);

    return 0;
}
