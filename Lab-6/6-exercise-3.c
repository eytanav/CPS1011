#include <stdio.h>
#include <string.h>

typedef struct
{
    char title[40];
    char author[40];
    float price;
} Book;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int indexes[], Book books[], int n, int (*cmp)(Book, Book))
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_or_max = i;
        for (int j = i + 1; j < n; j++)
        {
            // Compare books at the current indexes
            if (cmp(books[indexes[j] / sizeof(Book)], books[indexes[min_or_max] / sizeof(Book)]) < 0)
            {
                min_or_max = j;
            }
        }
        swap(&indexes[i], &indexes[min_or_max]);
    }
}

int compareByTitleAsc(Book b1, Book b2)
{
    return strcmp(b1.title, b2.title);
}

int compareByTitleDesc(Book b1, Book b2)
{
    return strcmp(b2.title, b1.title);
}

int compareByPriceAsc(Book b1, Book b2)
{
    return (b1.price > b2.price) - (b1.price < b2.price); // Ascending order
}

void displayBooks(FILE *fp, int indexes[], int n)
{
    Book book;
    for (int i = 0; i < n; i++)
    {
        fseek(fp, indexes[i], SEEK_SET);
        fread(&book, sizeof(Book), 1, fp);
        printf("Title: %s\nAuthor: %s\nPrice: $%.2f\n\n",
               book.title, book.author, book.price);
    }
}

int main(void)
{
    Book book1 = {
        "The C Programming Language",
        "Kernighan & Ritchie",
        29.99};
    Book book2 = {
        "Clean Code",
        "Robert C. Martin",
        24.99};

    FILE *fp = fopen("book.dat", "wb");
    if (fp == NULL)
    {
        perror("Unable to open file for writing");
        return 1;
    }
    fwrite(&book1, sizeof(Book), 1, fp);
    fwrite(&book2, sizeof(Book), 1, fp);
    fclose(fp);

    Book books[2] = {book1, book2};
    int indexes[2] = {0, sizeof(Book)}; // Offsets for book1 and book2

    fp = fopen("book.dat", "rb");
    if (fp == NULL)
    {
        perror("Unable to open file for reading");
        return 1;
    }

    selectionSort(indexes, books, 2, compareByTitleAsc);
    printf("Books sorted by title (ascending):\n\n");
    displayBooks(fp, indexes, 2);
    printf("--------------------------\n");

    selectionSort(indexes, books, 2, compareByTitleDesc);
    printf("Books sorted by title (descending):\n\n");
    displayBooks(fp, indexes, 2);
    printf("--------------------------\n");

    selectionSort(indexes, books, 2, compareByPriceAsc);
    printf("Books sorted by price (ascending):\n\n");
    displayBooks(fp, indexes, 2);

    fclose(fp);

    return 0;
}
