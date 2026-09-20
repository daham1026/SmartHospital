#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H

void saveBedStatus(int bedOccupancy[4][20]);

void savePatientRecords(int patientCount,
                        int patientID[],
                        char patientNames[][50],
                        int patientAge[],
                        int patientUrgency[],
                        int patientSpecialty[],
                        int patientAdmitted[],
                        int patientWard[],
                        int patientBed[],
                        int patientDays[]);

#endif
