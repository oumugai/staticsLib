#include <math.h>
#include "staticsStruct.h"

#define initDataSet(var) DataSet var = initializeDataSet();

float sumElements(DataSet input);
float average(DataSet input);
float variance(DataSet input);
float standardDeviation(DataSet input);
float sampleVariance(DataSet input);
float sampleStandardDeviation(DataSet input);
float covariance(DataSet inputX, DataSet inputY);
float correlationCoefficient(DataSet inputX, DataSet inputY);
float median(DataSet input);

DataSet initializeDataSet(){
	DataSet initData;
	int cnt;
	for(cnt = 0;cnt < 1024;cnt++){
		initData.element[cnt] = 0;
	}
	initData.size = 0;
	return initData;
}

void append(DataSet *input, float appendData){
	input->size++;
	input->element[input->size-1] = appendData;
}

void setData(DataSet *input, float data[], int size){
	int cnt;
	input->size = size;
	for(cnt = 0;cnt < size;cnt++){
		input->element[cnt] = data[cnt];
	}
}

statistics calcStatistics(DataSet input){
    statistics initCalcSet;
    initCalcSet.sum = sumElements(input);
    initCalcSet.average = average(input);
    initCalcSet.variance = variance(input);
	initCalcSet.standardDev = standardDeviation(input);
	initCalcSet.sampleVariance = sampleVariance(input);
	initCalcSet.sampleStandardDev = sampleStandardDeviation(input);
	initCalcSet.median = median(input);
    return initCalcSet;
}

float sumElements(DataSet input){
    int cnt;
    float sum = 0;
    for(cnt = 0;cnt < input.size;cnt++){
        sum+=input.element[cnt];
    }
    return sum;
}

float average(DataSet input){
    return sumElements(input)/(float)input.size;
}

float variance(DataSet input){
    float ave = average(input);
    int cnt;
    float sum = 0;
    for(cnt = 0;cnt < input.size;cnt++){
        sum += powf(input.element[cnt] - ave, 2.0);
    }
    return sum/(float)input.size;
}

float standardDeviation(DataSet input){
    return sqrtf(variance(input));
}

float sampleVariance(DataSet input){
    float ave = average(input);
    int cnt;
    float sum = 0;
    for(cnt = 0;cnt < input.size;cnt++){
        sum += powf(input.element[cnt] - ave, 2.0);
    }
    return sum/(float)(input.size-1.0);
}

float sampleStandardDeviation(DataSet input){
    return sqrtf(sampleVariance(input));
}

float median(DataSet input){
	return input.element[(int)(input.size/2)];
}

float covariance(DataSet inputX, DataSet inputY){
    float avex, avey;
    avex = average(inputX);
    avey = average(inputY);
    int cnt;
    float sum = 0;
    for(cnt = 0;cnt < inputX.size;cnt++){
        sum += (inputX.element[cnt] - avex) * (inputY.element[cnt] - avey);
    }
    return sum/(float)inputX.size;
}

float correlationCoefficient(DataSet inputX, DataSet inputY){
	return covariance(inputX,inputY)/(standardDeviation(inputX)*standardDeviation(inputY));
}
