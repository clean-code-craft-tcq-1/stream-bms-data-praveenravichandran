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

int main()
{
	FILE *fp;
   	char InputString[255];
	char* pend;
	
   	fp = fopen("./BMSApplication_Receiver/InputDataStream.txt", "r");
	
	while (fgets(InputString, 255, (FILE*)fp)) 
	{
		printf("%s", InputString); 
		char * token = strtok(InputString, ",");
		printf("InputString = %s\n",InputString);
		printf("token = %s\n",token);
		
   		// loop through the string to extract all other tokens
   		while( token != NULL ) 
		{
      			printf( " %s\n", token ); //printing each token
      			token = strtok(NULL, ",");
   		}
	}
	
	fclose(fp);
	
	return 0;
}
#endif 


