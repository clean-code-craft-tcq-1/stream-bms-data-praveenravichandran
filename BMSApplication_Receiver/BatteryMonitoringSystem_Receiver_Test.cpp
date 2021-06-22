#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "../testRx/catch.hpp"
#include "BatteryMonitoringSystem_Receiver_Main.h"

TEST_CASE("Check if minimum value for parameter is found or not") {
	float minValueCurrent = 15;
	float minValueNew = 0;
	
  	minValueNew = BMS_Receiver_calculateMinParameterValue(10,minValueCurrent);
	REQUIRE(minValueNew == 10);
	
	minValueNew = BMS_Receiver_calculateMinParameterValue(23,minValueCurrent);
	REQUIRE(minValueNew == minValueCurrent);
	
	minValueNew = BMS_Receiver_calculateMinParameterValue(15,minValueCurrent);
	REQUIRE(minValueNew == minValueCurrent);
}

TEST_CASE("Check if maximum value for parameter is found or not") {
	float maxValueCurrent = 15;
	float maxValueNew = 0;
	
  	maxValueNew = BMS_Receiver_calculateMaxParameterValue(10,maxValueCurrent);
	REQUIRE(maxValueNew == maxValueCurrent);
	
	maxValueNew = BMS_Receiver_calculateMaxParameterValue(23,maxValueCurrent);
	REQUIRE(maxValueNew == 23);
	
	maxValueNew = BMS_Receiver_calculateMaxParameterValue(15,maxValueCurrent);
	REQUIRE(maxValueNew == maxValueCurrent);
}

TEST_CASE("Check if moving average for parameter is found or not") {
	float tempValueSample[10]= {1,2,3,4,5,6,7,8,9,10};
	float movAvgValue = 0;
	
	/*Moving average for samples less than 5*/
	movAvgValue = BMS_Receiver_calculateMovingAverage(3,tempValueSample);
	REQUIRE(movAvgValue == 2);
	
	/*Moving average for samples 5*/
	movAvgValue = BMS_Receiver_calculateMovingAverage(8,tempValueSample);
	REQUIRE(movAvgValue == 7);
}

TEST_CASE("Check if all parameters for all Inputs have been printed or not") {
	BMS_Rx_Verify_Output_s BMS_Rx_Verify_Output = {0};
	
	BMS_Receiver_Main_Function();
	REQUIRE(BMS_Rx_Verify_Output.countPrint == 60); /*6 values to be printed for each I/P, we have 10I/Ps from sender ie 6*10=60*/
}
