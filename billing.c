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

float calculateWardCost(int ward, int days)
{
    if (ward == -1)
    {
        return 0;
    }

    return days * wardCosts[ward];
}

float calculateGrossTotal(float baseFee, float surcharge, float wardCost)
{
    return baseFee + surcharge + wardCost;
}

float calculateAgeSubsidy(float grossTotal, int age)
{
    if (age < 5 || age > 65)
    {
        return grossTotal * 0.15;
    }

    return 0;
}

float calculateFinalPayable(float grossTotal, float subsidy)
{
    return grossTotal - subsidy;
}
