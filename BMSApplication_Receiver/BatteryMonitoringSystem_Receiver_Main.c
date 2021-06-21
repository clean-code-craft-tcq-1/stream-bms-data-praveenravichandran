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

int main()
{
	FILE *fp;
   	char InputString[255];
	char * TempString;
	char * SOCString;
	float temp_Value;
	float soc_Value;
	
	char* pend;
	
   	fp = fopen("./BMSApplication_Receiver/InputDataStream.txt", "r");
	
	while (fgets(InputString, 255, (FILE*)fp)) 
	{
		printf("%s", InputString); 
		char * token = strtok(InputString, ",");
		TempString = token;
		
		token = strtok(NULL, ",");
		SOCString = token;
			
		printf("TempString = %s",TempString);
		printf("SOCString = %s",SOCString);
		
		temp_Value = getParameterValue(TempString);
		soc_Value = getParameterValue(SOCString);
		
		printf("Temp=%.2f",temp_Value);
		printf("SOC=%.2f",soc_Value);
	}
	
	fclose(fp);
	
	return 0;
}
#endif 


