#include "calcStatics.h"
#include <stdio.h>

int main(void){
	float inputData[] = {1.2, 2.3, 3.4, 5.6};
	
	initDataSet(test);
	setData(&test, inputData, sizeof(inputData)/sizeof(inputData[0]));
	initDataSet(test2);
	setData(&test2, inputData, sizeof(inputData)/sizeof(inputData[0]));

	printf("%d\n", test.size);
	//printf("%f\n", calcStatistics(test).standardDev);
	//printf("%f\n", calcStatistics(test).sampleStandardDev);
	//printf("%f\n", correlation(test, test2));
	printf("%f\n",calcStatistics(test).median);
	getchar();
	return 0;
}