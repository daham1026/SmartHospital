#include "billing.h"
#include "hospital_data.h"

float calculateWaitingTime(int specialty, int queueCount)
{
    return queueCount * specialtyTimes[specialty];
}
