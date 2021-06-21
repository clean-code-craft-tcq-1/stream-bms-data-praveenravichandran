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


int main(int argc, char *argv[])
{
 FILE *fp;
 char *filename;
 char ch;

  // Check if a filename has been specified in the command
  if (argc < 2)
   {
        printf("Missing Filename\n");
        return(1);
   }
   else
  {
        filename = argv[1];
        printf("Filename : %s\n", filename);
   }

   // Open file in read-only mode
   fp = fopen(filename,"r");

   // If file opened successfully, then print the contents
   if ( fp )
      {
        printf("File contents:\n");
        while ( (ch = fgetc(fp)) != EOF )
           {
                printf("%c",ch);
           }

       }
   else
      {
         printf("Failed to open the file\n");
        }

return(0);
}

