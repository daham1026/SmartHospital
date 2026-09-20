#include <stdio.h>
#include "file_handling.h"
#include "hospital_data.h"

void saveBedStatus(int bedOccupancy[4][20])
{
    FILE *file;

    int i;
    int j;

    file = fopen("beds_status.txt", "w");

    if (file == NULL)
    {
        printf("\nUnable to create beds_status.txt\n");
        return;
    }

    fprintf(file, "SMART HOSPITAL BED STATUS\n");
    fprintf(file, "\n");

    for (i = 0; i < 4; i++)
    {
        fprintf(file, "\n%s\n", wardNames[i]);

        for (j = 0; j < wardBeds[i]; j++)
        {
            fprintf(file, "Bed %d: ", j + 1);

            if (bedOccupancy[i][j] == 0)
            {
                fprintf(file, "Available\n");
            }
            else
            {
                fprintf(file, "Occupied\n");
            }
        }
    }

    fclose(file);

    printf("\nBed status saved to beds_status.txt\n");
}

void savePatientRecords(int patientCount,
                        int patientID[],
                        char patientNames[][50],
                        int patientAge[],
                        int patientUrgency[],
                        int patientSpecialty[],
                        int patientAdmitted[],
                        int patientWard[],
                        int patientBed[],
                        int patientDays[])
{
    FILE *file;

    int i;

    file = fopen("patient_records.txt", "w");

    if (file == NULL)
    {
        printf("\nUnable to create patient_records.txt\n");
        return;
    }

    fprintf(file, "SMART HOSPITAL PATIENT RECORDS\n");
    fprintf(file, "\n");

    for (i = 0; i < patientCount; i++)
    {
        fprintf(file, "\nPatient ID: PAT-%d\n",patientID[i]);

        fprintf(file, "Name: %s",patientNames[i]);

        fprintf(file, "Age: %d\n",patientAge[i]);

        fprintf(file, "Urgency Level: %d\n",patientUrgency[i]);

        fprintf(file, "Specialty ID: %d\n",patientSpecialty[i]);

        if (patientAdmitted[i] == 1)
        {
            fprintf(file, "Admitted: Yes\n");
            fprintf(file, "Ward ID: %d\n",patientWard[i]);

            fprintf(file, "Bed Number: %d\n",patientBed[i]);

            fprintf(file, "Days Admitted: %d\n",patientDays[i]);
        }
        else
        {
            fprintf(file, "Admitted: No\n");
            fprintf(file, "Ward: Not Applicable\n");
            fprintf(file, "Bed: Not Applicable\n");
            fprintf(file, "Days Admitted: 0\n");
        }
    }

    fclose(file);

    printf("\nPatient records saved to patient_records.txt\n");
}
