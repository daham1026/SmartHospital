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
            if (patientUrgency[patientOrder[j]] < patientUrgency[patientOrder[j + 1]])
            {
                temp = patientOrder[j];

                patientOrder[j] = patientOrder[j + 1];

                patientOrder[j + 1] = temp;
            }
        }
    }
}

void displayPriorityQueue(int patientOrder[],
                          int patientID[],
                          char patientNames[][50],
                          int patientUrgency[],
                          int patientCount)
{
    int i;
    int index;

    printf("\n-----------------------------------------\n");
    printf("          PATIENT PRIORITY QUEUE\n");
    printf("-----------------------------------------\n");

    if (patientCount == 0)
    {
        printf("No patients have been registered.\n");
        return;
    }

    printf("\nPriority Order:\n");
    printf("3 = Critical\n");
    printf("2 = Urgent\n");
    printf("1 = Normal\n\n");

    for (i = 0; i < patientCount; i++)
    {
        index = patientOrder[i];

        printf("%d. PAT-%d - %s - Urgency Level: %d\n",
               i + 1,
               patientID[index],
               patientNames[index],
               patientUrgency[index]);
    }
}
