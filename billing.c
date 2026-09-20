#include <stdio.h>
#include "billing.h"
#include "hospital_data.h"

int calculateWaitingTime(int specialty, int queueCount)
{
    return queueCount * specialtyTimes[specialty-1];
}

float calculateEmergencySurcharge(int specialty, int urgency)
{
    if (urgency == 1)
    {
        return 0;
    }
    else if (urgency == 2)
    {
        return specialtyFees[specialty-1] * 0.20;
    }
    else if (urgency == 3)
    {
        return specialtyFees[specialty-1] * 0.50;
    }

    return 0;
}

float calculateWardCost(int ward, int days)
{
    if (ward == -1)
    {
        return 0;
    }

    return days * wardCosts[ward-1];
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
                        int patientDays[],
                        int patientWaitingTime[])
{
    float baseFee;
    float surcharge;
    float wardCost;
    float grossTotal;
    float subsidy;
    float finalPayable;

    int specialty;
    int ward;
    int urgency;

    specialty = patientSpecialty[patientIndex] - 1;
    urgency = patientUrgency[patientIndex];

    baseFee = specialtyFees[specialty];

    surcharge = calculateEmergencySurcharge(
                    patientSpecialty[patientIndex],
                    urgency);

    if (patientAdmitted[patientIndex] == 1)
    {
        ward = patientWard[patientIndex] - 1;

        wardCost = calculateWardCost(
                       patientWard[patientIndex],
                       patientDays[patientIndex]);
    }
    else
    {
        ward = -1;
        wardCost = 0;
    }

    grossTotal = calculateGrossTotal(
                     baseFee,
                     surcharge,
                     wardCost);

    subsidy = calculateAgeSubsidy(
                  grossTotal,
                  patientAge[patientIndex]);

    finalPayable = calculateFinalPayable(
                       grossTotal,
                       subsidy);

    printf("\n----------------------------------------------------\n");
    printf("          SMART HOSPITAL ADMISSION & BILL\n");
    printf("----------------------------------------------------\n");

    printf("Patient ID          : PAT-%d\n", patientID[patientIndex]);
    printf("Patient Name        : %s\n", patientNames[patientIndex]);
    if (patientAge[patientIndex] < 5 ||
        patientAge[patientIndex] > 65)
    {
    printf("Age                 : %d Years (15%% Subsidy Eligible)\n",
               patientAge[patientIndex]);
    }
    else
    {
    printf("Age                 : %d Years\n",
               patientAge[patientIndex]);
    }
    printf("Specialty ID        : %d\n", patientSpecialty[patientIndex]);

    if (patientAdmitted[patientIndex] == 1)
    {
    printf("Assigned Ward       : %s (Bed #%02d)\n",
               wardNames[ward],
               patientBed[patientIndex]);
    }
    else
    {
    printf("Assigned Ward       : Not Admitted\n");
    }

     if (urgency == 1)
    {
    printf("Urgency Level       : Level 1 (Normal)\n");
    }
    else if (urgency == 2)
    {
    printf("Urgency Level       : Level 2 (Urgent)\n");
    }
    else
    {
    printf("Urgency Level       : Level 3 (Critical)\n");
    }


    printf("----------------------------------------------------\n");

       printf("Base Consultation Fee   : LKR %.2f\n",
           baseFee);

    if (urgency == 1)
    {
       printf("Emergency Surcharge     : LKR %.2f (0%%)\n",
               surcharge);
    }
    else if (urgency == 2)
    {
       printf("Emergency Surcharge     : LKR %.2f (20%%)\n",
               surcharge);
    }
    else
    {
       printf("Emergency Surcharge     : LKR %.2f (50%%)\n",
              surcharge);
    }

    if (patientAdmitted[patientIndex] == 1)
    {
       printf("Ward Stay Cost (%d Days) : LKR %.2f\n",
               patientDays[patientIndex],
               wardCost);
    }
    else
    {
        printf("Ward Stay Cost : LKR %.2f\n",
               wardCost);
    }

    printf("----------------------------------------------------------------------------------------\n");

    printf("Gross Total Bill     : LKR %.2f\n",
           grossTotal);

    if (patientAge[patientIndex] < 5 ||
        patientAge[patientIndex] > 65)
    {
        printf("Age Subsidy Discount : LKR -%.2f (15%%)\n",
               subsidy);
    }
    else
    {
        printf("Age Subsidy Discount : LKR -%.2f (0%%)\n",
               subsidy);
    }

    printf("----------------------------------------------------------------------------------------\n");

    printf("Final Payable Amount   : LKR %.2f\n",
           finalPayable);

    if (patientWaitingTime[patientIndex] == 0)
    {
    printf("Estimated Waiting Time : %.2f mins (Immediate Attention)\n",
               (float)patientWaitingTime[patientIndex]);
    }
    else
    {
        printf("Estimated Waiting Time : %.2f mins\n",
               (float)patientWaitingTime[patientIndex]);
    }

    printf("====================================================\n");
}
