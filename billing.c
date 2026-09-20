#include <stdio.h>
#include "billing.h"
#include "hospital_data.h"

float calculateWaitingTime(int specialty, int queueCount)
{
    return queueCount * specialtyTimes[specialty];
}

float calculateEmergencySurcharge(int specialty, int urgency)
{
    if (urgency == 1)
    {
        return 0;
    }
    else if (urgency == 2)
    {
        return specialtyFees[specialty] * 0.20;
    }
    else if (urgency == 3)
    {
        return specialtyFees[specialty] * 0.50;
    }

    return 0;
}

float calculateWardCost(int ward, int days)
{
    if (ward == -1)
    {
        return 0;
    }

    return days * wardCosts[ward];
}

float calculateGrossTotal(float baseFee, float surcharge, float wardCost)
{
    return baseFee + surcharge + wardCost;
}

float calculateAgeSubsidy(float grossTotal, int age)
{
    if (age < 5 || age > 65)
    {
        return grossTotal * 0.15;
    }

    return 0;
}

float calculateFinalPayable(float grossTotal, float subsidy)
{
    return grossTotal - subsidy;
}

void displayPatientBill(int patientIndex,
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
    printf("\n----------------------------------------------------\n");
    printf("          SMART HOSPITAL ADMISSION & BILL\n");
    printf("----------------------------------------------------\n");

    printf("Patient ID          : PAT-%d\n", patientID[patientIndex]);
    printf("Patient Name        : %s", patientNames[patientIndex]);
    printf("Age                 : %-2d Years\n", patientAge[patientIndex]);

    printf("Specialty ID        : %d\n", patientSpecialty[patientIndex]);

    if (patientAdmitted[patientIndex] == 1)
    {
        printf("Ward ID             : %d\n", patientWard[patientIndex]);
        printf("Bed Number          : %d\n", patientBed[patientIndex]);
        printf("Days Admitted       : %d\n", patientDays[patientIndex]);
    }
    else
    {
        printf("Ward                : Not Admitted\n");
        printf("Bed                 : Not Applicable\n");
    }

    printf("Urgency Level       : %d\n", patientUrgency[patientIndex]);

    printf("====================================================\n");
}
