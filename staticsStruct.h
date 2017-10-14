typedef struct{
    float element[1024];
    int size;
}DataSet;

typedef struct{
    float (*sum)(DataSet input);
    float (*average)(DataSet input);
    float (*variance)(DataSet input);
	float (*standardDev)(DataSet input);
	float (*sampleVariance)(DataSet input);
	float (*sampleStandardDev)(DataSet input);
	float (*covariance)(DataSet X, DataSet Y);
	float (*correlation)(DataSet X, DataSet Y);
	float (*median)(DataSet input);
}CalcStatistics;

typedef struct{
    float (*gaussian)(DataSet input);
	float (*Bernoulli)(DataSet input);
	float (*binomial)(DataSet input);
}CalcDist;
