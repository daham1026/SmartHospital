#include "billing.h"
#include "hospital_data.h"

float calculateWaitingTime(int specialty, int queueCount)
{
    return queueCount * specialtyTimes[specialty];
}

float calculateEmergencySurcharge(int specialty, int urgency)
{
    if (urgency == 1)
    {
        return 0;
    }
    else if (urgency == 2)
    {
        return specialtyFees[specialty] * 0.20;
    }
    else if (urgency == 3)
    {
        return specialtyFees[specialty] * 0.50;
    }

    return 0;
}
