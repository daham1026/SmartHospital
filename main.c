#include <stdio.h>
#include "hospital_data.h"
#include "bed.h"
#include "patient.h"
#include "billing.h"

int main()
{
    int bedOccupancy[4][20];
    int specialtyQueueCount[4] = {0, 0, 0, 0};

    int patientID[MAX_PATIENTS];
    char patientNames[MAX_PATIENTS][50];
    int patientAge[MAX_PATIENTS];
    int patientUrgency[MAX_PATIENTS];
    int patientSpecialty[MAX_PATIENTS];
    int patientAdmitted[MAX_PATIENTS];
    int patientWard[MAX_PATIENTS];
    int patientDays[MAX_PATIENTS];

    printf(" ===============================================\n");
    printf("|            SMART HOSPITAL SYSTEM             |\n");
    printf(" ===============================================\n");
    printf("\n");

    initializeBeds(bedOccupancy);

    initializePatients(patientID,patientNames,patientAge,patientUrgency,patientSpecialty,patientAdmitted,patientWard,patientDays);

    displayHospitalInformation();

    displayBedStatus(bedOccupancy);

    registerPatient(0,patientID,patientNames,patientAge,patientUrgency,patientSpecialty,patientAdmitted,patientWard,patientDays);

    printf("\n--- Waiting Time Test ---\n");

    printf("Cardiology queue: %d patients\n", specialtyQueueCount[2]);

    printf("Estimated waiting time: %.2f minutes\n",calculateWaitingTime(2, specialtyQueueCount[2]));

    specialtyQueueCount[2]++;

    printf("Cardiology queue after registration: %d patients\n",specialtyQueueCount[2]);

    printf("Next estimated waiting time: %.2f minutes\n",calculateWaitingTime(2, specialtyQueueCount[2]));

    printf("\n--- Emergency Surcharge Test ---\n");

    printf("Normal surcharge: LKR %.2f\n",
       calculateEmergencySurcharge(2, 1));

    printf("Urgent surcharge: LKR %.2f\n",
       calculateEmergencySurcharge(2, 2));

    printf("Critical surcharge: LKR %.2f\n",
       calculateEmergencySurcharge(2, 3));

    printf("\n--- Ward Cost Test ---\n");

    printf("General Ward, 2 days: LKR %.2f\n",
       calculateWardCost(0, 2));

    printf("ICU, 2 days: LKR %.2f\n",
       calculateWardCost(3, 2));

    printf("Not admitted: LKR %.2f\n",
       calculateWardCost(-1, 0));

    printf("\n--- Complete Billing Test ---\n");

    float baseFee = 4500.00;
    float surcharge = 2250.00;
    float wardCost = 50000.00;
    int age = 70;

    float grossTotal = calculateGrossTotal(baseFee, surcharge, wardCost);

    float subsidy = calculateAgeSubsidy(grossTotal, age);

    float finalPayable = calculateFinalPayable(grossTotal, subsidy);

    printf("Base Fee: LKR %.2f\n", baseFee);
    printf("Emergency Surcharge: LKR %.2f\n", surcharge);
    printf("Ward Cost: LKR %.2f\n", wardCost);
    printf("Gross Total: LKR %.2f\n", grossTotal);
    printf("Age Subsidy: LKR %.2f\n", subsidy);
    printf("Final Payable: LKR %.2f\n", finalPayable);

    return 0;

}
