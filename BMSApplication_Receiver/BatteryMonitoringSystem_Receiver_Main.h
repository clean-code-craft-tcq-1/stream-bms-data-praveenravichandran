/* ******************************************************************************
 ***     \file        BatteryMonitoringSystem_Receiver_Main.h
 ***     \ingroup     Evaluation-TCQ
 ***     \author      Rohith K N
 ***
 ***     \brief       Header file for the module
 ***
 ***     \par         File_description
 ***                  This file have the declarations of the variables and methods of the module
 ***
 *****************************************************************************/
#ifndef BMS_RX_H_
#define BMS_RX_H_
/*=============================================================================
 =======                            INCLUDES                             =======
 ============================================================================*/
/*------ standard includes -------*/

/*------ module includes -------*/

int  readInputFromPipe(char *paramIP);
float getParameterValue(char * TempString);
float calculateMinParameterValue(float paramValue, float paramMin);
float calculateMaxParameterValue(float paramValue, float paramMax);
void printParameter(char paramName[100],char paramStatus[100],float paramValue);
float calculateMovingAverage(int count,float param_Value[]);

#endif /*BMS_RX_H_*/
