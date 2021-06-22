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
