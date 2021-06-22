int  readInputFromPipe(char *paramIP);
float getParameterValue(char * TempString);
float calculateMinParameterValue(float paramValue, float paramMin);
float calculateMaxParameterValue(float paramValue, float paramMax);
void printParameter(char paramName[100],char paramStatus[100],float paramValue);
float calculateMovingAverage(int count,float param_Value[]);
