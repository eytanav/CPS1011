#include <stdio.h>

int main()
{
    int dogs, cats, pets;

    printf("How many dogs do you have?\n");

    scanf("%d", &dogs);

    printf("So you have %d dog(s)!\n", dogs);

    printf("How many cats do you have?\n");

    scanf("%d", &cats);

    pets = cats + dogs;

    printf("So you have %d pets in total!", pets);

    return 0;
}
