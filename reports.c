#include <stdio.h>
#include "reports.h"
#include "hospital_data.h"
#include "billing.h"

void displayPerformanceReport(int patientCount,
                              int patientID[],
                              char patientNames[][50],
                              int patientAge[],
                              int patientUrgency[],
                              int patientSpecialty[],
                              int patientAdmitted[],
                              int patientWard[],
                              int patientDays[],
                              int bedOccupancy[4][20])
{
    int i;
    int j;

    int criticalCount = 0;
    int urgentCount = 0;
    int normalCount = 0;

    float totalRevenue = 0;
    float totalDiscounts = 0;

    float baseFee;
    float surcharge;
    float wardCost;
    float grossTotal;
    float subsidy;
    float finalPayable;

    int occupiedBeds;
    float occupancyPercentage;

    int highestPatientIndex = -1;
    float highestBill = 0;

    for (i = 0; i < patientCount; i++)
    {

        if (patientUrgency[i] == 3)
        {
            criticalCount++;
        }
        else if (patientUrgency[i] == 2)
        {
            urgentCount++;
        }
        else if (patientUrgency[i] == 1)
        {
            normalCount++;
        }

        //Calculate the patient's bill.

        baseFee = specialtyFees[patientSpecialty[i] - 1];

        surcharge = calculateEmergencySurcharge(patientSpecialty[i],patientUrgency[i]);

        if (patientAdmitted[i] == 1)
        {
            wardCost = calculateWardCost(patientWard[i],patientDays[i]);
        }
        else
        {
            wardCost = 0;
        }

        grossTotal = calculateGrossTotal(baseFee,surcharge,wardCost);

        subsidy = calculateAgeSubsidy(grossTotal,patientAge[i]);

        finalPayable = calculateFinalPayable(grossTotal,subsidy);

        totalRevenue = totalRevenue + finalPayable;

        totalDiscounts = totalDiscounts + subsidy;

        if (finalPayable > highestBill)
        {
            highestBill = finalPayable;
            highestPatientIndex = i;
        }
    }

    printf("\n----------------------------------------\n");
    printf("       HOSPITAL PERFORMANCE REPORT\n");
    printf("----------------------------------------\n");

    printf("\n--- Patient Counts by Urgency ---\n");
    printf("\n");
    printf("Critical : %d\n", criticalCount);
    printf("Urgent   : %d\n", urgentCount);
    printf("Normal   : %d\n", normalCount);

    printf("\n--- Financial Summary ---\n");
    printf("\n");
    printf("Total Revenue  : LKR %.2f\n", totalRevenue);
    printf("Total Discounts: LKR %.2f\n", totalDiscounts);

    printf("\n--- Ward Occupancy ---\n");
    printf("\n");

    for (i = 0; i < 4; i++)
    {
        occupiedBeds = 0;

        for (j = 0; j < wardBeds[i]; j++)
        {
            if (bedOccupancy[i][j] == 1)
            {
                occupiedBeds++;
            }
        }

        occupancyPercentage =
            ((float) occupiedBeds / wardBeds[i]) * 100;

        printf("%s: %.2f%% occupied\n",wardNames[i],occupancyPercentage);
    }

    printf("\n--- Highest-Paying Patient ---\n");
    printf("\n");

    if (highestPatientIndex == -1)
    {
        printf("No patients have been registered.\n");
    }
    else
    {
        printf("Patient ID   : PAT-%d\n",1001 + highestPatientIndex);

        printf("Patient Name : %s\n",patientNames[highestPatientIndex]);

        printf("Bill         : LKR %.2f\n",highestBill);
    }
}
