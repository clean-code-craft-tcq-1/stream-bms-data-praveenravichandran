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
static float tempMovingAvg = 0;
static float SOCMovingAvg = 0;
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

float calculateMinParameterValue(float paramValue, float paramMin)
{
	if(paramValue<paramMin)
	{
		return paramValue;
	}
	return paramMin;	
}

float calculateMaxParameterValue(float paramValue, float paramMax)
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

float calculateMovingAverage(int count,float param_Value[])
{
	float sum = 0;
	
	if(count <5)
	{
		while(count != 0)
		{
			sum = sum + param_Value[count];
			count = count - 1;
		}
	}
	else
	{
		sum = param_Value[count] + param_Value[count-1] + param_Value[count-2] + param_Value[count-3] + param_Value[count-4];
	}
	
	tempMovingAvg = sum/5;
	
	return tempMovingAvg;
}

int main()
{
	FILE *fp;
   	char InputString[255];
	char * TempString;
	char * SOCString;
	float temp_Value[10];
	float soc_Value[10];
	float tempSum = 0;
	float SOCSum = 0;
	float tempMin = 100;
	float SOCMin = 100;
	float tempMax = 0;
	float SOCMax = 0;
	int count = 0;
	float tempMovingAverage;
	float SOCMovingAverage;
	
	char* pend;
	
   	fp = fopen("./BMSApplication_Receiver/InputDataStream.txt", "r");
	
	while (fgets(InputString, 255, (FILE*)fp)) 
	{
		count = count + 1;
		
		char * token = strtok(InputString, ",");
		TempString = token;
		
		token = strtok(NULL, ",");
		SOCString = token;
		
		temp_Value[count] = getParameterValue(TempString);
		soc_Value[count] = getParameterValue(SOCString);
		
		tempMin = calculateMinParameterValue(temp_Value[count],tempMin);
		SOCMin = calculateMinParameterValue(soc_Value[count],SOCMin);
		
		tempMax = calculateMaxParameterValue(temp_Value[count],tempMax);
		SOCMax = calculateMaxParameterValue(soc_Value[count],SOCMax);
		
		tempSum = tempSum + temp_Value[count];
		tempMovingAverage = calculateMovingAverage(count,temp_Value);
		SOCMovingAverage = calculateMovingAverage(count,soc_Value);
		
		printf("\nStart For Data %d\n",count);
		printParameter("Temperature","minimum",tempMin);
		printParameter("Temperature","maximum",tempMax);
		printParameter("SOC","minimum",SOCMin);
		printParameter("SOC","maximum",SOCMax);
		printParameter("Temperature","moving average",tempMovingAverage);
		printParameter("SOC","moving average",SOCMovingAverage);
		printf("End for Data %d\n\n",count);
	}
	
	fclose(fp);
	
	return 0;
}
#endif 


