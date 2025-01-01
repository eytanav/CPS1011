#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define NAME_LENGTH 50

typedef struct
{
    char name[NAME_LENGTH];
    char surname[NAME_LENGTH];
    int id;
    float monthlySalary;
} Employee;

void sortById(Employee *employees[], int n);
void sortBySurname(Employee *employees[], int n);
void printEmployees(Employee *employees[], int n);

int main()
{
    Employee database[MAX_EMPLOYEES] = {
        {"John", "Doe", 102, 3500.0},
        {"Alice", "Smith", 101, 4200.0},
        {"Bob", "Johnson", 104, 3000.0},
        {"Eve", "Brown", 103, 3800.0}};

    int n = 4;

    Employee *indexById[MAX_EMPLOYEES];
    Employee *indexBySurname[MAX_EMPLOYEES];

    for (int i = 0; i < n; i++)
    {
        indexById[i] = &database[i];
        indexBySurname[i] = &database[i];
    }

    sortById(indexById, n);
    sortBySurname(indexBySurname, n);

    printf("Employees sorted by ID:\n");
    printEmployees(indexById, n);

    printf("\nEmployees sorted by Surname:\n");
    printEmployees(indexBySurname, n);

    return 0;
}

void sortById(Employee *employees[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (employees[j]->id > employees[j + 1]->id)
            {
                Employee *temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }
}

void sortBySurname(Employee *employees[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(employees[j]->surname, employees[j + 1]->surname) > 0)
            {
                Employee *temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }
}

void printEmployees(Employee *employees[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("ID: %d, Name: %s %s, Monthly Salary: %.2f\n",
               employees[i]->id,
               employees[i]->name,
               employees[i]->surname,
               employees[i]->monthlySalary);
    }
}
