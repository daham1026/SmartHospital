#include <stdio.h>
#include "bed.h"
#include "hospital_data.h"

void initializeBeds(int bedOccupancy[4][20])
{
    int i;
    int j;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 20; j++)
        {
            bedOccupancy[i][j] = 0;
        }
    }
}

void displayBedStatus(int bedOccupancy[4][20])
{
    int i;
    int j;

    printf("\n--- Bed Status ---\n");

    for (i = 0; i < 4; i++)
    {
        printf("\n%s\n", wardNames[i]);

        printf("\n");

        for (j = 0; j < wardBeds[i]; j++)
        {
            printf("Bed %d: ", j + 1);

            if (bedOccupancy[i][j] == 0)
            {
                printf("Available\n");
            }
            else
            {
                printf("Occupied\n");
            }
        }
    }
}

int allocateBed(int bedOccupancy[4][20], int ward)
{
    int j;

    for (j = 0; j < wardBeds[ward]; j++)
    {
        if (bedOccupancy[ward][j] == 0)
        {
            bedOccupancy[ward][j] = 1;

            return j + 1;
        }
    }

    return -1;
}
