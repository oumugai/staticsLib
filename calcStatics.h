#include <math.h>

#define  initStatics(var) calcStatics var = init()

typedef struct{
    float element[1024];
    int size;
}dataSet;

typedef struct{
    float (*sum)(dataSet input);
    float (*average)(dataSet input);
    float (*dispersion)(dataSet input);
}calcStatics

float init(){
    calcStatics calcSet;
    calcSet.sum = sumElements;
    calcSet.average = average;
    calcSet.variance = variance;
    return calcSet;
}

float sumElements(dataSet input){
    int cnt;
    float sum = 0;
    for(cnt = 0;cnt < input.size;cnt++){
        sum+=dataSet.element[cnt];
    }
    return sum;
}

float average(dataSet input){
    return sumElements(input)/(float)input.size;
}

float variance(dataSet input){
    float ave = sumElements(input);
    int cnt;
    float sum = 0;
    for(cnt = 0;cnt < input.size;cnt++){
        sum += powf(input.element[cnt] - ave, 2);
    }
    return sum/(float)input.size;
}

float standardDeviation(dataSet input){
    return sqrtf(variance(input));
}

float covariance(dataSet inputX, dataSet inputY){
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
