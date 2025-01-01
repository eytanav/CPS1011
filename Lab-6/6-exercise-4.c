#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct
{
    char title[40];
    char author[40];
    float price;
} Book;

void swap(int *a, int *b);
void selectionSort(int indexes[], FILE *fp, int n, int (*cmp)(Book, Book));
int compareByTitleAsc(Book b1, Book b2);
int compareByTitleDesc(Book b1, Book b2);
int compareByPriceAsc(Book b1, Book b2);
void displayBooks(FILE *fp, int indexes[], int n);
void saveIndexes(const char *filename, int indexes[], int n);
int loadIndexes(const char *filename, int indexes[], int max_books);

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int indexes[], FILE *fp, int n, int (*cmp)(Book, Book))
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_or_max = i;
        for (int j = i + 1; j < n; j++)
        {
            Book book1, book2;

            fseek(fp, indexes[j], SEEK_SET);
            fread(&book1, sizeof(Book), 1, fp);
            fseek(fp, indexes[min_or_max], SEEK_SET);
            fread(&book2, sizeof(Book), 1, fp);

            if (cmp(book1, book2) < 0)
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
    return (b1.price > b2.price) - (b1.price < b2.price);
}

void displayBooks(FILE *fp, int indexes[], int n)
{
    Book book;
    for (int i = 0; i < n; i++)
    {
        fseek(fp, indexes[i], SEEK_SET);
        fread(&book, sizeof(Book), 1, fp);
        printf("Title: %s\nAuthor: %s\nPrice: $%.2f\n\n", book.title, book.author, book.price);
    }
}

void saveIndexes(const char *filename, int indexes[], int n)
{
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL)
    {
        perror("Unable to open index file for writing");
        return;
    }
    fwrite(indexes, sizeof(int), n, fp);
    fclose(fp);
}

int loadIndexes(const char *filename, int indexes[], int max_books)
{
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        return 0;
    }
    int n = 0;
    while (fread(&indexes[n], sizeof(int), 1, fp) == 1)
    {
        n++;
        if (n >= max_books)
            break;
    }
    fclose(fp);
    return n;
}

int main(void)
{
    Book books[MAX_BOOKS];
    int indexes[MAX_BOOKS];
    int num_books = 0;

    num_books = loadIndexes("book_indexes.dat", indexes, MAX_BOOKS);

    FILE *fp = fopen("book.dat", "rb+");
    if (fp == NULL)
    {
        fp = fopen("book.dat", "wb+");
        if (fp == NULL)
        {
            perror("Unable to open file for reading and writing");
            return 1;
        }
    }

    if (num_books == 0)
    {
        Book book1 = {"The C Programming Language", "Kernighan & Ritchie", 29.99};
        Book book2 = {"Clean Code", "Robert C. Martin", 24.99};
        fwrite(&book1, sizeof(Book), 1, fp);
        fwrite(&book2, sizeof(Book), 1, fp);
        num_books = 2;

        indexes[0] = 0;
        indexes[1] = sizeof(Book);
    }

    selectionSort(indexes, fp, num_books, compareByTitleAsc);
    saveIndexes("book_indexes.dat", indexes, num_books);

    selectionSort(indexes, fp, num_books, compareByTitleAsc);
    printf("Books sorted by title (ascending):\n\n");
    displayBooks(fp, indexes, num_books);
    printf("--------------------------\n");

    selectionSort(indexes, fp, num_books, compareByTitleDesc);
    printf("Books sorted by title (descending):\n\n");
    displayBooks(fp, indexes, num_books);
    printf("--------------------------\n");

    selectionSort(indexes, fp, num_books, compareByPriceAsc);
    printf("Books sorted by price (ascending):\n\n");
    displayBooks(fp, indexes, num_books);

    fclose(fp);
    return 0;
}
