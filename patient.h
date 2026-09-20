#ifndef PATIENT_H
#define PATIENT_H

#define MAX_PATIENTS 150

void initializePatients(int patientID[],
                        char patientNames[][50],
                        int patientAge[],
                        int patientUrgency[],
                        int patientSpecialty[],
                        int patientAdmitted[],
                        int patientWard[],
                        int patientDays[],
                        int patientBed[]);

void registerPatient(int patientIndex,
                     int patientID[],
                     char patientNames[][50],
                     int patientAge[],
                     int patientUrgency[],
                     int patientSpecialty[],
                     int patientAdmitted[],
                     int patientWard[],
                     int patientDays[],
                     int patientBed[],
                     int bedOccupancy[4][20]);

#endif
