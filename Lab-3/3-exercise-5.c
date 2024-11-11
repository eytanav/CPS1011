#include <stdio.h>
#define MAX_NUMS 20
#define MAX_VALUE 100 // Since numbers are between 1 and 100

// Function to calculate the median
double calc_median(int nums[], int count)
{
    double median;

    if (count == 1)
    {
        return median = nums[0];
    }
    else if (count % 2 == 0)
    {
        return median = (nums[(count / 2) - 1] + nums[count / 2]) / 2.0; // Use 2.0 to ensure floating-point division
    }
    else
    {
        return median = nums[count / 2];
    }
}

// Function to calculate the mode
void calc_mode(int nums[], int count)
{
    int frequency[MAX_VALUE + 1] = {0}; // Array to store frequencies for numbers 0 to 100
    int max_frequency = 0;
    int mode[MAX_VALUE]; // Array to store the modes
    int mode_count = 0;

    // Count the frequency of each number
    for (int i = 0; i < count; i++)
    {
        frequency[nums[i]]++; // Increment the frequency of the number
    }

    // Find the highest frequency
    for (int i = 1; i <= MAX_VALUE; i++)
    {
        if (frequency[i] > max_frequency)
        {
            max_frequency = frequency[i];
        }
    }

    // Collect all numbers with the highest frequency (the mode(s))
    for (int i = 1; i <= MAX_VALUE; i++)
    {
        if (frequency[i] == max_frequency && max_frequency > 1)
        {
            mode[mode_count++] = i; // Store the mode
        }
    }

    // Print the mode(s)
    if (mode_count == 0)
    {
        printf("No mode\n");
    }
    else
    {
        printf("The mode is: ");
        for (int i = 0; i < mode_count; i++)
        {
            printf("%d ", mode[i]);
        }
        printf("\n");
    }
}

int main(void)
{
    int running = 1, count = 0, temp;
    int nums[MAX_NUMS];
    double mean = 0; // Initialize mean to 0
    while (running == 1 && count < MAX_NUMS)
    {
        printf("Input a number (between 1 - 100, ascending order) (press '0' to quit) (Number %d): ", (count + 1));
        scanf("%d", &temp);
        if (temp != 0)
        {
            nums[count] = temp;
            mean += nums[count];
            count++;
        }
        else
        {
            running = 0;
        }
    }

    if (count > 0)
    {
        mean /= count;
        double median = calc_median(nums, count);
        printf("The mean is: %.2lf\n", mean);
        calc_mode(nums, count); // Calculate and print the mode
        printf("The median is: %.1lf\n", median);
    }
    else
    {
        printf("No numbers were entered.\n");
    }

    return 0;
}
