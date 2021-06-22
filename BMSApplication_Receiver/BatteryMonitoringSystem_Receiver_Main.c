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
#include <string.h>
#include <stdlib.h>

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
 
BMS_Rx_Parama_IP_s BMS_Receiver_Get_Parameters_from_Input(char InputString[])
{
	BMS_Rx_Parama_IP_s BMS_Rx_Parama_IP;
	
	char * token = strtok(InputString, ",");
	BMS_Rx_Parama_IP.TempString = token;
	
	token = strtok(NULL, ",");
	BMS_Rx_Parama_IP.SOCString = token;	
	
	return BMS_Rx_Parama_IP;
}

float BMS_Receiver_getParameterValue(char * String)
{
	char * token = strtok(String, ":");	
	token = strtok(NULL, ":");
	float temp = atof(token);
	
	return temp;
}

float BMS_Receiver_calculateMinParameterValue(float paramValue, float paramMin)
{
	if(paramValue<paramMin)
	{
		return paramValue;
	}
	return paramMin;	
}

float BMS_Receiver_calculateMaxParameterValue(float paramValue, float paramMax)
{
	if(paramValue>paramMax)
	{
		return paramValue;
	}
	return paramMax;	
}

void BMS_Receiver_printParameter(char paramName[],char paramStatus[],float paramValue)
{
	printf("%s have %s value as %.2f\n",paramName,paramStatus,paramValue);
}

float BMS_Receiver_calculateMovingAverage(int count,float param_Value[])
{
	float movingAvg = 0;
	float sum = 0;
	
	if(count < MOVING_AVERAGE_SAMPLES)
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
	
	movingAvg = sum/MOVING_AVERAGE_SAMPLES;
	
	return movingAvg;
}

void BMS_Receiver_Print_Parameters_to_console(int count,BMS_Rx_Print_Params_s BMS_Rx_Print_Params)
{
	printf("\nStart For Data %d\n",count);
	BMS_Receiver_printParameter("Temperature","minimum",BMS_Rx_Print_Params.tempMin);
	BMS_Receiver_printParameter("Temperature","maximum",BMS_Rx_Print_Params.tempMax);
	BMS_Receiver_printParameter("SOC","minimum",BMS_Rx_Print_Params.SOCMin);
	BMS_Receiver_printParameter("SOC","maximum",BMS_Rx_Print_Params.SOCMax);
	BMS_Receiver_printParameter("Temperature","moving average",BMS_Rx_Print_Params.tempMovingAverage);
	BMS_Receiver_printParameter("SOC","moving average",BMS_Rx_Print_Params.SOCMovingAverage);
	printf("End for Data %d\n\n",count);
}

void BMS_Receiver_Main_Function(void)
{
	
	FILE *fp;
   	char InputString[255];
	float temp_Value[NUMBER_OF_SAMPLES];
	float soc_Value[NUMBER_OF_SAMPLES];
	int count = 0;
	BMS_Rx_Parama_IP_s BMS_Rx_Parama_IP;
	BMS_Rx_Print_Params_s BMS_Rx_Print_Params = {100,100,0,0,0,0};

	
   	fp = fopen("./BMSApplication_Receiver/InputDataStream.txt", "r");
	
	while (fgets(InputString, 255, (FILE*)fp)) 
	{
		count = count + 1;
		
		/*Get Input Parameters from the Input file read*/
		BMS_Rx_Parama_IP = BMS_Receiver_Get_Parameters_from_Input(InputString);
		
		/*Get the parameter values*/
		temp_Value[count] = BMS_Receiver_getParameterValue(BMS_Rx_Parama_IP.TempString);
		soc_Value[count] = BMS_Receiver_getParameterValue(BMS_Rx_Parama_IP.SOCString);
		
		/*Calculate minimum for each parameter*/
		BMS_Rx_Print_Params.tempMin = BMS_Receiver_calculateMinParameterValue(temp_Value[count],BMS_Rx_Print_Params.tempMin);
		BMS_Rx_Print_Params.SOCMin = BMS_Receiver_calculateMinParameterValue(soc_Value[count],BMS_Rx_Print_Params.SOCMin);
		
		/*Calculate maximum for each parameter*/
		BMS_Rx_Print_Params.tempMax = BMS_Receiver_calculateMaxParameterValue(temp_Value[count],BMS_Rx_Print_Params.tempMax);
		BMS_Rx_Print_Params.SOCMax = BMS_Receiver_calculateMaxParameterValue(soc_Value[count],BMS_Rx_Print_Params.SOCMax);
		
		/*Calculate moving average for each parameter*/
		BMS_Rx_Print_Params.tempMovingAverage = BMS_Receiver_calculateMovingAverage(count,temp_Value);
		BMS_Rx_Print_Params.SOCMovingAverage = BMS_Receiver_calculateMovingAverage(count,soc_Value);
		
		/*Print parameters to console*/
		BMS_Receiver_Print_Parameters_to_console(count,BMS_Rx_Print_Params);
	}
	
	fclose(fp);	
	
}

int main()
{	
	BMS_Receiver_Main_Function();
	
	return 0;
}
#endif 


