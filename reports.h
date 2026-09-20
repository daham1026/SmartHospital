#ifndef REPORTS_H
#define REPORTS_H

void displayPerformanceReport(int patientCount,
                              int patientID[],
                              char patientNames[][50],
                              int patientAge[],
                              int patientUrgency[],
                              int patientSpecialty[],
                              int patientAdmitted[],
                              int patientWard[],
                              int patientDays[],
                              int bedOccupancy[4][20]);

#endif
