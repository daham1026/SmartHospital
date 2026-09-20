#include <stdio.h>
#include "patient.h"
#include "hospital_data.h"

void initializePatients(int patientID[],
                        char patientNames[][50],
                        int patientAge[],
                        int patientUrgency[],
                        int patientSpecialty[],
                        int patientAdmitted[],int patientWard[],
                        int patientDays[])
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
                     int patientDays[])
{
    patientID[patientIndex] = 1001 + patientIndex;

    printf("\n--- Patient Registration ---\n");

    printf("Patient Name: ");
    fgets(patientNames[patientIndex], 50, stdin);

    printf("Patient Age: ");
    scanf("%d", &patientAge[patientIndex]);

    printf("Urgency Level (1 = Normal, 2 = Urgent, 3 = Critical): ");
    scanf("%d", &patientUrgency[patientIndex]);

    printf("Specialty ID (1-4): ");
    scanf("%d", &patientSpecialty[patientIndex]);

    printf("Is the patient admitted to a ward? (1 = Yes, 0 = No): ");
    scanf("%d", &patientAdmitted[patientIndex]);

    if (patientAdmitted[patientIndex] == 1)
    {
        printf("Ward ID (1-4): ");
        scanf("%d", &patientWard[patientIndex]);

        printf("Days Admitted: ");
        scanf("%d", &patientDays[patientIndex]);
    }
    else
    {
        patientWard[patientIndex] = -1;
        patientDays[patientIndex] = 0;
    }

    printf("\nPatient registered successfully.\n");
    printf("Patient ID: PAT-%d\n", patientID[patientIndex]);
}
