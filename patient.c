#include <stdio.h>
#include <string.h>
#include "patient.h"
#include "hospital_data.h"
#include "bed.h"

void initializePatients(int patientID[],
                        char patientNames[][50],
                        int patientAge[],
                        int patientUrgency[],
                        int patientSpecialty[],
                        int patientAdmitted[],
                        int patientWard[],
                        int patientDays[],
                        int patientBed[],
                        int patientWaitingTime[])
{
    int i;


    for (i = 0; i < MAX_PATIENTS; i++)
    {
        patientID[i] = 0;
        patientNames[i][0] = '\0';
        patientAge[i] = 0;
        patientUrgency[i] = 0;
        patientSpecialty[i] = 0;
        patientAdmitted[i] = 0;
        patientWard[i] = -1;
        patientDays[i] = 0;
        patientBed[i] = -1;
        patientWaitingTime[i] = 0;

    }
}

void registerPatient(int patientIndex,
                     int patientID[],
                     char patientNames[][50],
                     int patientAge[],
                     int patientUrgency[],
                     int patientSpecialty[],
                     int patientAdmitted[],
                     int patientWard[],
                     int patientDays[],
                     int patientBed[],
                     int bedOccupancy[4][20])
{
    patientID[patientIndex] = 1001 + patientIndex;

    printf("\n--- Patient Registration ---\n");

    printf("\n");

    printf("Patient Name: ");
    fgets(patientNames[patientIndex], 50, stdin);

    patientNames[patientIndex][strcspn(patientNames[patientIndex], "\n")] = '\0';

    printf("Patient Age: ");

    while (scanf("%d", &patientAge[patientIndex]) != 1 || patientAge[patientIndex] < 0 || patientAge[patientIndex] > 120)
    {
    printf("\nInvalid age\n\n");

    while (getchar() != '\n');

    printf("Patient Age: ");
    }

    printf("Urgency Level (1=Normal, 2=Urgent, 3=Critical): ");

    while (scanf("%d", &patientUrgency[patientIndex]) != 1 || patientUrgency[patientIndex] < 1 || patientUrgency[patientIndex] > 3)
{
    printf("\nInvalid urgency level.\n\n");

    while (getchar() != '\n');

    printf("Urgency Level (1=Normal, 2=Urgent, 3=Critical): ");
}

    printf("Specialty ID (1-4): ");
    while(scanf("%d", &patientSpecialty[patientIndex]) !=1 || patientSpecialty[patientIndex] < 1 || patientSpecialty[patientIndex] > 4){
    printf("\nInvalid specialty ID\n\n");
     while(getchar() !='\n');

    printf("Specialty ID (1-4): ");
    }

    printf("Is the patient admitted to a ward? (1 = Yes, 0 = No): ");
    while (scanf("%d", &patientAdmitted[patientIndex]) !=1 ||( patientAdmitted[patientIndex] != 1 && patientAdmitted[patientIndex] != 0))
   {
    printf("\nInvalid choice.\n\n");
      while(getchar() !='\n');
    printf("Is the patient admitted to a ward? (1 = Yes, 0 = No): ");
   }

    if (patientAdmitted[patientIndex] == 1)
    {
    printf("Ward ID (1-4): ");

    while (scanf("%d", &patientWard[patientIndex]) !=1 || patientWard[patientIndex] < 1 || patientWard[patientIndex] > 4)
    {
        printf("\nInvalid ward ID.\n\n");
        while(getchar() !='\n');

        printf("Ward ID (1-4): ");
    }

    printf("Days Admitted: ");
    while ( scanf("%d", &patientDays[patientIndex])!=1 || patientDays[patientIndex] < 1 || patientDays[patientIndex] > 365)
    {
        printf("\nInvalid number of days.\n\n ");
        while(getchar() !='\n');
        printf("Days Admitted: ");
    }

     patientBed[patientIndex] = allocateBed(bedOccupancy, patientWard[patientIndex] - 1);

    if (patientBed[patientIndex] == -1)
    {
        printf("\nNo beds are available in this ward.\n");

        patientAdmitted[patientIndex] = 0;
        patientWard[patientIndex] = -1;
        patientBed[patientIndex] = -1;
        patientDays[patientIndex] = 0;
    }
    else
    {
        printf("Bed Assigned: %d\n",
               patientBed[patientIndex]);
    }
}
    else
    {
    patientWard[patientIndex] = -1;
    patientBed[patientIndex] = -1;
    patientDays[patientIndex] = 0;
    }

    printf("\nPatient registered successfully.\n");
    printf("Patient ID: PAT-%d\n", patientID[patientIndex]);
}
