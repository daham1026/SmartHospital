#include <stdio.h>
#include "sorting.h"

void sortPatientsByPriority(int patientOrder[],
                            int patientUrgency[],
                            int patientCount)
{
    int i;
    int j;
    int temp;

    for (i = 0; i < patientCount; i++)
    {
        patientOrder[i] = i;
    }

    for (i = 0; i < patientCount - 1; i++)
    {
        for (j = 0; j < patientCount - 1 - i; j++)
        {
            if (patientUrgency[patientOrder[j]] <
                patientUrgency[patientOrder[j + 1]])
            {
                temp = patientOrder[j];

                patientOrder[j] = patientOrder[j + 1];

                patientOrder[j + 1] = temp;
            }
        }
    }
}
