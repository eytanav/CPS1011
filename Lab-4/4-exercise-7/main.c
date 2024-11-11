#include <stdio.h>
#include "4-exercise-1.h"
#include "4-exercise-2.h"
#include "4-exercise-3.h"
#include "4-exercise-4.h"
#include "4-exercise-5.h"
#include "4-exercise-6.h"

void displayMenu()
{
    printf("Select an exercise:\n");
    printf("1. Factorial (Iterative and Recursive)\n");
    printf("2. Fibonacci (Iterative and Recursive)\n");
    printf("3. GCD (Iterative and Recursive)\n");
    printf("4. Decimal to Hexadecimal and String Reversal\n");
    printf("5. String Analysis\n");
    printf("6. Ceiling and Floor (With and Without <math.h>)\n");
    printf("0. Exit\n");
}

int main()
{
    int choice;
    do
    {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            runExercise1();
            break;
        case 2:
            runExercise2();
            break;
        case 3:
            runExercise3();
            break;
        case 4:
            runExercise4();
            break;
        case 5:
            runExercise5();
            break;
        case 6:
            runExercise6();
            break;
        case 0:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);
    return 0;
}
