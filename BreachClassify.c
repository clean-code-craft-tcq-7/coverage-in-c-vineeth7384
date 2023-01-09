#include "BreachClassify.h"


CoolingInfo CoolingInfoTable[]= {
    {PASSIVE_COOLING , PASSIVE_COOLING_LOWERLIMIT,PASSIVE_COOLING_UPPERLIMIT},
    {HI_ACTIVE_COOLING,HI_ACTIVE_COOLING_LOWERLIMIT,HI_ACTIVE_COOLING_UPPERLIMIT},
    {MED_ACTIVE_COOLING,MED_ACTIVE_COOLING_LOWERLIMIT,MED_ACTIVE_COOLING_UPPERLIMIT},
};

BreachType classifyTemperatureBreach(
   CoolingType coolingType, double temperatureInC) {
   int lowerLimit = 0;
   int upperLimit = 0;
   for ( int CoolingInfoTableIndex = 0; CoolingInfoTableIndex < MAXIMUM_COOLING_TYPE;CoolingInfoTableIndex++)
   {
      if(CoolingInfoTable[CoolingInfoTableIndex].coolingtype == coolingType)
      {
         lowerLimit = CoolingInfoTable[CoolingInfoTableIndex].LowerLimit;
         upperLimit = CoolingInfoTable[CoolingInfoTableIndex].UpperLimit; 
         break;
      }
   }
  
   return inferBreach(temperatureInC, lowerLimit, upperLimit);
}