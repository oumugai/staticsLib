#include "calcStatics.h"
#include <stdio.h>

int main(void){
	initCalcStatistics(calc);
	float inputData[] = {1.2, 2.3, 3.4, 5.6};
	
	initDataSet(test);
	setData(&test, inputData, sizeof(inputData)/sizeof(inputData[0]));
	initDataSet(test2);
	setData(&test2, inputData, sizeof(inputData)/sizeof(inputData[0]));

	printf("%d\n", test.size);
	//printf("%f\n", calc.standardDev(test));
	//printf("%f\n", calc.sampleStandardDev(test));
	//printf("%f\n",calc.correlation(test, test2));
	printf("%f\n",calc.median(test));
	getchar();
	return 0;
}