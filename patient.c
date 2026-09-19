#include "patient.h"

void initializePatients(int patientID[],
                        char patientNames[][50],
                        int patientAge[],
                        int patientUrgency[],
                        int patientSpecialty[],
                        int patientAdmitted[],
                        int patientWard[],
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
