#include <stdio.h>
#include <stdlib.h>

int *copyArray(const int *arr, int size);

int main()
{
    int original[] = {1, 2, 3, 4, 5};
    int actualSize = sizeof(original) / sizeof(original[0]);
    int oversizedSize = 10; // Larger than the actual size

    // size argument larger than the destination size
    int *copiedArray = copyArray(original, oversizedSize);

    printf("Original array: ");
    for (int i = 0; i < actualSize; i++)
    {
        printf("%d ", original[i]);
    }
    printf("\n");

    printf("Copied array with oversized size: ");
    for (int i = 0; i < oversizedSize; i++)
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
