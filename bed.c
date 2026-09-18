#include "bed.h"

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
