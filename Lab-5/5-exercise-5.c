#include <stdio.h>

#define RANGE 101

int main()
{
    double f_values[RANGE][RANGE][RANGE];

    for (int x = 0; x < RANGE; x++)
    {
        for (int y = 0; y < RANGE; y++)
        {
            for (int z = 0; z < RANGE; z++)
            {
                f_values[x][y][z] = x + 6 * y + 7.2 * z;
            }
        }
    }

    int sample_x = 10, sample_y = 20, sample_z = 30;
    printf("f(%d, %d, %d) = %f\n", sample_x, sample_y, sample_z, f_values[sample_x][sample_y][sample_z]);

    return 0;
}
