#include <stdio.h>
#include "hospital_data.h"
#include "bed.h"

int main()
{
    int bedOccupancy[4][20];
    int allocatedBed;

    printf("===============================================\n");
    printf("             SMART HOSPITAL SYSTEM\n");
    printf("===============================================\n");
    printf("\n");
    printf("System is starting...\n");

    initializeBeds(bedOccupancy);
    displayHospitalInformation();
    displayBedStatus(bedOccupancy);
    allocatedBed = allocateBed(bedOccupancy, 0);

    if (allocatedBed == -1)
    {
        printf("\nNo bed available.\n");
    }
    else
    {
        printf("\nAllocated Bed: %d\n", allocatedBed);
    }

    displayBedStatus(bedOccupancy);

    return 0;
}
