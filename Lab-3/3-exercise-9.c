#include <stdio.h>
#include <stdlib.h>

#define MIN_VALUE -100.0 // Set the minimum threshold for valid numbers
#define MAX_VALUE 100.0  // Set the maximum threshold for valid numbers
#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"

int main()
{
    FILE *inputFile, *outputFile;
    double number;
    int result;

    // Open input file for reading
    inputFile = fopen(INPUT_FILE, "r");
    if (inputFile == NULL)
    {
        fprintf(stderr, "Error: Could not open input file %s.\n", INPUT_FILE);
        return 1;
    }

    // Open output file for writing
    outputFile = fopen(OUTPUT_FILE, "w");
    if (outputFile == NULL)
    {
        fprintf(stderr, "Error: Could not open output file %s.\n", OUTPUT_FILE);
        fclose(inputFile); // Close input file if output file fails
        return 1;
    }

    // Process each entry in the input file
    while ((result = fscanf(inputFile, "%lf", &number)) != EOF)
    {
        if (result == 1)
        { // Valid number read
            // Check if number is within the defined range
            if (number >= MIN_VALUE && number <= MAX_VALUE)
            {
                fprintf(outputFile, "%f\n", number); // Write valid number to output file
            }
            else
            {
                fprintf(stderr, "Warning: Number %f is out of the acceptable range [%f, %f].\n",
                        number, MIN_VALUE, MAX_VALUE);
            }
        }
        else
        { // Invalid input encountered
            fprintf(stderr, "Error: Non-numeric or malformed input encountered. Skipping...\n");
            fscanf(inputFile, "%*s"); // Skip the invalid input
        }
    }

    // Close files
    fclose(inputFile);
    fclose(outputFile);

    printf("Processing completed. Check %s for results.\n", OUTPUT_FILE);
    return 0;
}
