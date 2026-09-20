#ifndef BED_H
#define BED_H

void initializeBeds(int bedOccupancy[4][20]);

void displayBedStatus(int bedOccupancy[4][20]);

int allocateBed(int bedOccupancy[4][20], int ward);

#endif
