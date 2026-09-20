#include <stdio.h>
#include "hospital_data.h"

const char specialtyNames[4][30] = {"General Practice","Paediatrics","Cardiology","Neurology"};
const float specialtyFees[4] = {1500.00,2500.00,4500.00,5000.00};
const int specialtyTimes[4] = {15,20,30,30};
const int specialtyCaps[4] = {30,20,12,10};
const char wardNames[4][30] = {"General Ward","Paediatric Ward","Surgical Ward","ICU"};
const float wardCosts[4] = {3000.00,6000.00,12000.00,25000.00};
const int wardBeds[4] = {20,10,10,5};

void displayHospitalInformation()
{
    int i;

    printf("\n--- Doctor Specialties ---\n");
    printf("\n");
    printf("____________________________________________________________________________\n");
    printf("ID  |   SPECIALITY     |     FEE     | CONSULTATION TIME | DAILY PATIENT CAP\n");
    printf("----------------------------------------------------------------------------\n");

    for (i = 0; i < 4; i++)
    {
        printf(" %-3d|%-17s | LKR %.2f | %8d minutes  |%8d patients\n",
               i + 1,
               specialtyNames[i],
               specialtyFees[i],
               specialtyTimes[i],
               specialtyCaps[i]);
    }
    printf("----------------------------------------------------------------------------\n");
    printf("\n--- Hospital Wards ---\n");
    printf("\n");
    printf("___________________________________________________________\n");
    printf("ID  |      WARD        |      FEE         | NUMBER OF BEDS \n");
    printf("-----------------------------------------------------------\n");



    for (i = 0; i < 4; i++)
    {
        printf(" %-2d | %-16s | LKR %8.2f p.d | %4d beds\n",
               i + 1,
               wardNames[i],
               wardCosts[i],
               wardBeds[i]);
    }
     printf("-----------------------------------------------------------\n");
}
