#ifndef SORTING_H
#define SORTING_H

void sortPatientsByPriority(int patientOrder[],
                            int patientUrgency[],
                            int patientCount);

void displayPriorityQueue(int patientOrder[],
                          int patientID[],
                          char patientNames[][50],
                          int patientUrgency[],
                          int patientCount);

#endif
