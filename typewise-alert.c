#include "typewise-alert.h"
#include "Check_Limit.h"
#include "Alert.h"
#include "BreachClassify.h"

void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC,char* msgBufresult)
{

  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);
  SendAlertMessage(alertTarget, breachType,msgBufresult);
}


