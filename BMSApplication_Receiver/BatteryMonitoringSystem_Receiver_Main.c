/* ******************************************************************************
 ***
 ***     \file        BatteryMonitoringSystem_Receiver_Main.c
 ***     \ingroup     Assessment-TCQ
 ***     \author      Rohith K N
 ***
 ***     \brief       Main file for Battery Monitoring System Receiver
 ***
 ***     \par         File_description
 ***                  This file explores more about functions
 ***
 *****************************************************************************/
 
/*=============================================================================
 =======                            INCLUDES                             =======
 ============================================================================*/
/*------ standard includes -------*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

/*------ module includes --------*/
#include "BatteryMonitoringSystem_Receiver_Main.h"

/*=============================================================================
 =======               DEFINES & MACROS FOR GENERAL PURPOSE              =======
 =============================================================================*/

/*=============================================================================
 =======                       CONSTANTS  &  TYPES                       =======
 =============================================================================*/

/*=============================================================================
 =======                VARIABLES & MESSAGES & RESSOURCEN                =======
 ==============================================================================*/

/*=============================================================================
 =======                              METHODS                            =======
 =============================================================================*/

 #ifndef UNIT_TEST   
float getParameterValue(char * TempString)
{
	char * token = strtok(TempString, ":");	
	token = strtok(NULL, ":");
	float temp = atof(token);
	return temp;
}

int calculateMinParameterValue(float paramValue, float paramMin)
{
	if(paramValue<paramMin)
	{
		return paramValue;
	}
	return paramMin;	
}

int calculateMaxParameterValue(float paramValue, float paramMax)
{
	if(paramValue>paramMax)
	{
		return paramValue;
	}
	return paramMax;	
}

void printParameter(char paramName[100],char paramStatus[100],float paramValue)
{
	printf("%s have %s value as %.2f\n",paramName,paramStatus,paramValue);
}

int main()
{
	FILE *fp;
   	char InputString[255];
	char * TempString;
	char * SOCString;
	float temp_Value;
	float soc_Value;
	float tempMin = 100;
	float SOCMin = 100;
	float tempMax = 0;
	float SOCMax = 0;
	
	char* pend;
	
   	fp = fopen("./BMSApplication_Receiver/InputDataStream.txt", "r");
	
	while (fgets(InputString, 255, (FILE*)fp)) 
	{
		char * token = strtok(InputString, ",");
		TempString = token;
		
		token = strtok(NULL, ",");
		SOCString = token;
		
		temp_Value = getParameterValue(TempString);
		soc_Value = getParameterValue(SOCString);
		
		tempMin = calculateMinParameterValue(temp_Value,tempMin);
		SOCMin = calculateMinParameterValue(soc_Value,SOCMin);
		
		tempMax = calculateMaxParameterValue(temp_Value,tempMax);
		SOCMax = calculateMaxParameterValue(soc_Value,SOCMax);
		
		printParameter("Temperature","minimum",tempMin);
		printParameter("Temperature","maximum",SOCMin);
		printParameter("SOC","minimum",tempMax);
		printParameter("SOC","maximum",SOCMax);
	}
	
	fclose(fp);
	
	return 0;
}
#endif 


