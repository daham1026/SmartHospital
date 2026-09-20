#ifndef BILLING_H
#define BILLING_H

float calculateWaitingTime(int specialty, int queueCount);
float calculateEmergencySurcharge(int specialty, int urgency);
float calculateWardCost(int ward, int days);
float calculateGrossTotal(float baseFee, float surcharge, float wardCost);
float calculateAgeSubsidy(float grossTotal, int age);
float calculateFinalPayable(float grossTotal, float subsidy);

#endif
