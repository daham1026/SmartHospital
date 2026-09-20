#include <stdio.h>
#include "hospital_data.h"
#include "bed.h"
#include "patient.h"
#include "billing.h"
#include "sorting.h"
#include "reports.h"
#include "file_handling.h"

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
     printf("4. Display Patient Priority Queue\n");
     printf("5. Display Patient Bill\n");
     printf("6. Display Performance Report\n");
     printf("7. Save Bed Status to File\n");
     printf("8. Save Patient Records to File\n");
     printf("9. Exit\n");


     printf("\nEnter your choice: ");

     while(scanf("%d", &choice) !=1 || choice < 1 || choice > 9){
        printf("\nInvalid Input\n");

        while (getchar()!='\n');

        printf("\nEnter your choice: ");
     }

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

                    registerPatient(patientCount,
                                    patientID,
                                    patientNames,
                                    patientAge,
                                    patientUrgency,
                                    patientSpecialty,
                                    patientAdmitted,
                                    patientWard,
                                    patientDays,
                                    patientBed,
                                    bedOccupancy);

                    patientCount++;

                    sortPatientsByPriority(patientOrder,
                                            patientUrgency,
                                            patientCount);
                 }
                  else
                {
                    printf("\nMaximum number of patients reached.\n");
                }

                break;

            case 4:
                displayPriorityQueue(patientOrder,
                                     patientID,
                                     patientNames,
                                     patientUrgency,
                                     patientCount);
                break;

            case 5:
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

            case 6:
                displayPerformanceReport(patientCount,
                                         patientID,
                                         patientNames,
                                         patientAge,
                                         patientUrgency,
                                         patientSpecialty,
                                         patientAdmitted,
                                         patientWard,
                                         patientDays,
                                         bedOccupancy);
            break;

            case 7:
                 saveBedStatus(bedOccupancy);
                 break;

            case 8:
                 savePatientRecords(patientCount,
                                    patientID,
                                    patientNames,
                                    patientAge,
                                    patientUrgency,
                                    patientSpecialty,
                                    patientAdmitted,
                                    patientWard,
                                    patientBed,
                                    patientDays);
                 break;

             case 9:
                printf("\nThank you for using Smart Hospital System.\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 9);

    return 0;

}
