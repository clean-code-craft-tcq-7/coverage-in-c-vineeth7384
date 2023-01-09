#include "typewise-alert.h"
#include "Check_Limit.h"
typedef struct
{
	CoolingType coolingtype;
	int LowerLimit;
	int UpperLimit;
}CoolingInfo;

#define PASSIVE_COOLING_LOWERLIMIT 0
#define PASSIVE_COOLING_UPPERLIMIT 35
#define HI_ACTIVE_COOLING_LOWERLIMIT 0
#define HI_ACTIVE_COOLING_UPPERLIMIT 45
#define MED_ACTIVE_COOLING_LOWERLIMIT 0
#define MED_ACTIVE_COOLING_UPPERLIMIT 40
#define MAXIMUM_COOLING_TYPE 3

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);