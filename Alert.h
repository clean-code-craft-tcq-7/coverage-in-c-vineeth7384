#include "typewise-alert.h"
typedef struct
{
	AlertTarget Target ;
	void (*AlertCallback)(BreachType,char*);
}AlertTable;
typedef struct
{
   BreachType breachtype;
   const char*FirstMessage;
   const char*SecondMessage;
}sendToEmailMessage;
void sendToController(BreachType breachType,char* msgBufresult);
void sendToEmail(BreachType breachType,char* msgBufresult);
void SendAlertMessage(AlertTarget alertTarget,BreachType breachType,char* msgBufresult);
#define MAXALERTTYPE 2