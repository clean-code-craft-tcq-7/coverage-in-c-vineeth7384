#include "typewise-alert.h"
#include "Check_Limit.h"
#include "Alert.h"
#include "BreachClassify.h"

void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC)
{

  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);
  SendAlertMessage(alertTarget, breachType);
}


