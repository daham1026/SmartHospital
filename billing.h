#ifndef BILLING_H
#define BILLING_H

float calculateWaitingTime(int specialty, int queueCount);
float calculateEmergencySurcharge(int specialty, int urgency);
float calculateWardCost(int ward, int days);

#endif
