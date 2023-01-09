#include "Alert.h"
#include<stdio.h>


sendToEmailMessage sendToEmailMessageInfo [] ={
	{TOO_LOW,"To:  a.b@c.com","Hi, the temperature is too low\n"},
	{TOO_HIGH,"To:  a.b@c.com","Hi, the temperature is too high\n"}
};


AlertTable AlertTableInfo[] ={
	{TO_CONTROLLER,&sendToController},
	{TO_EMAIL,&sendToController }
};

void SendAlertMessage(AlertTarget alertTarget,BreachType breachType)
{
	for (int AlertTableIndex= 0; AlertTableIndex < MAXALERTTYPE ;AlertTableIndex++)
	{
		if (AlertTableInfo[AlertTableIndex].Target == alertTarget)
		{
		   AlertTableInfo[AlertTableIndex].AlertCallback(breachType);
		   break;
		}
	}
}

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) 
{
  const char* recepient = "a.b@c.com";
  for(int sendToEmailMessageInfoIndex = 0; sendToEmailMessageInfoIndex<=1 ;sendToEmailMessageInfoIndex++)
  {
	if(sendToEmailMessageInfo[sendToEmailMessageInfoIndex].breachtype == breachType)
	{
		printf("%s",sendToEmailMessageInfo[sendToEmailMessageInfoIndex].FirstMessage);
		printf("%s",sendToEmailMessageInfo[sendToEmailMessageInfoIndex].SecondMessage);
		break;
	}
	
  }
}