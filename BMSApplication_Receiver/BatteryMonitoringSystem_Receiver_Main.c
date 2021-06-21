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
#include<stdlib.h>
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
int  readInputFromPipe(char *stringIP)
{
	int length=0;
	if(stringIP != NULL)
	{
		//scanf("%s",stringIP);
		//printf("%s\n",stringIP);
		//printf("%c\n",stringIP[0]);
    		//length = strlen(stringIP);
    		printf("%d\n",length);
		
    		stringIP[length] = '\n';
    		stringIP[length + 1] = '\0';
		
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	char stringIP[25];
	
	fgets(stringIP, sizeof stringIP, stdin);
   		printf("%s\n",stringIP);
		printf("%c\n",stringIP[0]);
	
		scanf("%s",stringIP);
		printf("%s\n",stringIP);
		printf("%c\n",stringIP[0]);
	
	if (stringIP[strlen(stringIP)-1] == '\n') 
	{
        	// read full line
		scanf("%s",stringIP);
		printf("%s\n",stringIP);
		printf("%c\n",stringIP[0]);
    	} else 
	{
        	// line was truncated
    	}
	
	int readStatus = readInputFromPipe(stringIP);
	
	if(readStatus == 1)
	{
		float paramBuffer[2] = { 0.f };
		
		  int i = 0, j = 0; //index counter

 		char par[15]; //string for each parameter 
  		int parNum = 0;  //count of parameters

		// while ((stringIP[i] != '\n'))
		//{
		
					/* Read each parameter */
					//for (j = 0;stringIP[i] != ',';j++, i++)
					//{
					//	par[j] = stringIP[i];
					//}

					//par[j] = '\0'; //Adding end of string
		
					/* Convert string to float number to evaluate further */
					//paramBuffer[parNum] = atof(par);
		
					//printf("Paramter value = %f\n", paramBuffer[parNum]); //for debug purpose

					/* Iterate to next parameter in the buffer*/ 
					//parNum++; 

					/*Escape Comma separated character*/
					//i++;
			//}

 
		
	}
	return 0;
}
#endif
