#include <stdio.h>
#include "hospital_data.h"
#include "bed.h"
#include "patient.h"

int main()
{
    int bedOccupancy[4][20];

    int patientID[MAX_PATIENTS];
    char patientNames[MAX_PATIENTS][50];
    int patientAge[MAX_PATIENTS];
    int patientUrgency[MAX_PATIENTS];
    int patientSpecialty[MAX_PATIENTS];
    int patientAdmitted[MAX_PATIENTS];
    int patientWard[MAX_PATIENTS];
    int patientDays[MAX_PATIENTS];

    printf("===============================================\n");
    printf("             SMART HOSPITAL SYSTEM\n");
    printf("===============================================\n");
    printf("\n");
    printf("System is starting...\n");

    initializeBeds(bedOccupancy);

    initializePatients(patientID,
                       patientNames,
                       patientAge,
                       patientUrgency,
                       patientSpecialty,
                       patientAdmitted,
                       patientWard,
                       patientDays);

    displayHospitalInformation();

    displayBedStatus(bedOccupancy);

    return 0;
}
