#include <stdio.h>
#include <string.h>

// Max name length is 11 due to null terminator
void get_employee_data(char names[][11], char surnames[][11], int ages[], double salaries[], int index)
{
    printf("\nEnter details for employee %d:\n", index + 1);

    printf("Name (max 10 characters): ");
    scanf("%10s", names[index]);

    printf("Surname (max 10 characters): ");
    scanf("%10s", surnames[index]);

    printf("Age: ");
    scanf("%d", &ages[index]);

    printf("Monthly Salary: ");
    scanf("%lf", &salaries[index]);
}

void display_table_header(int precision)
{
    printf("\n%-5s %-10s %-10s %-5s %*s %*s\n",
           "No", "Name", "Surname", "Age",
           precision + 7, "Monthly", precision + 7, "Yearly Total");
    printf("------------------------------------------------------------\n");
}

void display_employee(const char *name, const char *surname, int age, double salary, int entry_no, int precision)
{
    double yearly_salary = salary * 13;
    printf("%-5d %-10.10s %-10.10s %-5d %*.2f %*.2f\n",
           entry_no, name, surname, age,
           precision + 7, salary, precision + 7, yearly_salary);
}

int main()
{
    char names[10][11];
    char surnames[10][11];
    int ages[10];
    double salaries[10];
    int precision;
    int entry_count = 0;
    double total_salary = 0.0;

    printf("Enter the desired precision for salary columns: ");
    scanf("%d", &precision);

    while (entry_count < 10)
    {
        get_employee_data(names, surnames, ages, salaries, entry_count);
        total_salary += salaries[entry_count];
        entry_count++;

        // Display after each 5 entries
        if (entry_count % 5 == 0 || entry_count == 10)
        {
            display_table_header(precision);
            for (int i = 0; i < entry_count; i++)
            {
                display_employee(names[i], surnames[i], ages[i], salaries[i], i + 1, precision);
            }
        }
    }

    // Calculate and display average monthly salary
    double average_salary = total_salary / entry_count;
    printf("\nAverage Monthly Salary: %.*f\n", precision, average_salary);

    return 0;
}
