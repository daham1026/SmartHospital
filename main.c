#include <stdio.h>
#include "hospital_data.h"
#include "bed.h"

int main()
{
    int bedOccupancy[4][20];

    printf("===============================================\n");
    printf("             SMART HOSPITAL SYSTEM\n");
    printf("===============================================\n");
    printf("\n");
    printf("System is starting...\n");

    initializeBeds(bedOccupancy);
    displayHospitalInformation();
    displayBedStatus(bedOccupancy);

    return 0;
}
