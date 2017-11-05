typedef struct{
    float element[1024];
    int size;
}DataSet;

typedef struct{
    float sum;
    float average;
    float variance;
	float skewness;
	float kurtosis;
	float standardDev;
	float sampleVariance;
	float sampleStandardDev;
	float median;
}statistics;

typedef struct{
    float (*gaussian)(DataSet input);
	float (*Bernoulli)(DataSet input);
	float (*binomial)(DataSet input);
}CalcDist;
