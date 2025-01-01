#include <stdio.h>
#include <stdlib.h>

int *copyArray(const int *arr, int size);

int main()
{
    int original[] = {4, 5, 2, 15, 8, 29};
    int size = sizeof(original) / sizeof(original[0]);

    int *copiedArray = copyArray(original, size);

    printf("Original array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", original[i]);
    }

    printf("\nCopied array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", copiedArray[i]);
    }
    printf("\n");

    free(copiedArray);

    return 0;
}

int *copyArray(const int *arr, int size)
{
    if (arr == NULL || size <= 0)
    {
        return NULL;
    }

    int *copy = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        copy[i] = arr[i];
    }
    return copy;
}
