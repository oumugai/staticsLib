#include "calcStatics.h"

float multifactorial(int n){
	unsigned int result = 1;
	for(cnt = 1;cnt <= n;cnt++){
		result *= cnt;
	}
	return (float)result;
}

float convination(int n, int k){
	return multifactorial(n)/(multifactorial(n-k)*multifactorial(k));
}

//----------------------continuous probability distribution--------------------//
float gaussianDistribution(float ave, float var, float x){
	return (1/(sqrtf(2*M_PI*var)))*expf(-powf(x-ave, 2.0)/(2*var));
}

//float 

//-----------------------discrete probability distribution---------------------//
float binomialDistribution(int n, float p, int x){
	return convination(n, x)*powf(p, x)*powf((1-p), n-x);
}

float bernoulliDistribution(float p, int x){
	return powf(p, x)*powf((1-p), n-x);
}

float poissonDistribution(float lmd, int x){
	return powf(lmd, x)*expf(-lmd)/multifactorial(x);
}

float hypergeometricDistribution(int N, int K, int n, int x){
	return convination(n, x)*convination(N-n, K-x)/convination(N, K);
}