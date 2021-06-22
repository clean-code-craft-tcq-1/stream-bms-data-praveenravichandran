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

#define NUMBER_OF_SAMPLES 	10 /*As per sender*/
#define MOVING_AVERAGE_SAMPLES 5

typedef struct 
{
	char * TempString;
	char * SOCString;
}BMS_Rx_Parama_IP_s;

typedef struct 
{
	float tempMin;
	float SOCMin;
	float tempMax;
	float SOCMax;
	float tempMovingAverage;
	float SOCMovingAverage;
	int countPrint;
}BMS_Rx_Print_Params_s;

void BMS_Receiver_Main_Function(void);

BMS_Rx_Parama_IP_s BMS_Receiver_Get_Parameters_from_Input(char InputString[]);
int  readInputFromPipe(char *paramIP);
float BMS_Receiver_getParameterValue(char * String);
float BMS_Receiver_calculateMinParameterValue(float paramValue, float paramMin);
float BMS_Receiver_calculateMaxParameterValue(float paramValue, float paramMax);
void BMS_Receiver_printParameter(char paramName[],char paramStatus[],float paramValue);
float BMS_Receiver_calculateMovingAverage(int count,float param_Value[]);
void BMS_Receiver_Print_Parameters_to_console(int count,BMS_Rx_Print_Params_s BMS_Rx_Print_Params);
#endif /*BMS_RX_H_*/
