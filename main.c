#include <stdio.h>
#include "hospital_data.h"
#include "bed.h"
#include "patient.h"
#include "billing.h"
#include "sorting.h"

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
    int patientBed[MAX_PATIENTS];
    int patientOrder[MAX_PATIENTS];

    int patientCount = 0;
    int choice;
    int patientIndex;
    int tempPatientID;

    initializeBeds(bedOccupancy);

    initializePatients(patientID,patientNames,patientAge,patientUrgency,patientSpecialty,patientAdmitted,patientWard,patientDays,patientBed);

  do
  {
    printf("\n ===============================================\n");
    printf("|            SMART HOSPITAL SYSTEM             |\n");
    printf(" ===============================================\n");
    printf("\n");

     printf("1. Display Hospital Information\n");
     printf("2. Display Bed Status\n");
     printf("3. Register Patient\n");
     printf("4. Display Patient Bill\n");
     printf("5. Exit\n");

     printf("\nEnter your choice: ");
      scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                 displayHospitalInformation();
                 break;

            case 2:
                 displayBedStatus(bedOccupancy);
                 break;

            case 3:
                 if (patientCount < MAX_PATIENTS)
                 {
                    getchar();

                    registerPatient(patientCount,patientID,patientNames,patientAge,patientUrgency,patientSpecialty,patientAdmitted,patientWard,patientDays,patientBed);

                    patientCount++;

                    //test

                    sortPatientsByPriority(patientOrder,
                                            patientUrgency,
                                            patientCount);

                printf("\nCurrent Priority Order:\n");

                for (patientIndex = 0; patientIndex < patientCount; patientIndex++)
                {
                    printf("Patient ID: PAT-%d - Urgency Level: %d\n",
                                    patientID[patientOrder[patientIndex]],
                                    patientUrgency[patientOrder[patientIndex]]);
                }
                 }

                 //
                  else
                {
                    printf("\nMaximum number of patients reached.\n");
                }

                break;

            case 4:
                if (patientCount == 0)
                {
                    printf("\nNo patients have been registered yet.\n");
                }
                else
                {
                    printf("\nEnter patient ID PAT-: ");
                    scanf("%d", &tempPatientID);

                    patientIndex=tempPatientID-1001+1;


                    if (patientIndex >= 1 && patientIndex <= patientCount)
                    {
                        displayPatientBill(patientIndex - 1,
                                            patientID,
                                            patientNames,
                                            patientAge,
                                            patientUrgency,
                                            patientSpecialty,
                                            patientAdmitted,
                                            patientWard,
                                            patientBed,
                                            patientDays);
                    }
                    else
                    {
                        printf("\nInvalid patient number.\n");
                    }
                }

                break;

            case 5:
                printf("\nThank you for using Smart Hospital System.\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 5);

    printf("\n--- Waiting Time Test ---\n");

    printf("\n");

    printf("Cardiology queue: %d patients\n", specialtyQueueCount[2]);

    printf("Estimated waiting time: %.2f minutes\n",calculateWaitingTime(2, specialtyQueueCount[2]));

    specialtyQueueCount[2]++;

    printf("Cardiology queue after registration: %d patients\n",specialtyQueueCount[2]);

    printf("Next estimated waiting time: %.2f minutes\n",calculateWaitingTime(2, specialtyQueueCount[2]));

    printf("\n--- Emergency Surcharge Test ---\n");

    printf("\n");

    printf("Normal surcharge: LKR %.2f\n",
       calculateEmergencySurcharge(2, 1));

    printf("Urgent surcharge: LKR %.2f\n",
       calculateEmergencySurcharge(2, 2));

    printf("Critical surcharge: LKR %.2f\n",
       calculateEmergencySurcharge(2, 3));

    printf("\n--- Ward Cost Test ---\n");

    printf("\n");

    printf("General Ward, 2 days: LKR %.2f\n",
       calculateWardCost(0, 2));

    printf("ICU, 2 days: LKR %.2f\n",
       calculateWardCost(3, 2));

    printf("Not admitted: LKR %.2f\n",
       calculateWardCost(-1, 0));

    printf("\n--- Complete Billing Test ---\n");

    printf("\n");

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
