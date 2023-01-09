#include "typewise-alert.h"
typedef struct
{
	AlertTarget Target ;
	void (*AlertCallback)(BreachType);
}AlertTable;
typedef struct
{
   BreachType breachtype;
   const char*FirstMessage;
   const char*SecondMessage;
}sendToEmailMessage;
void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
void SendAlertMessage(AlertTarget alertTarget,BreachType breachType);
#define MAXALERTTYPE 2