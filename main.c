#include <stdio.h>
#include <math.h>

#define SIZE 90
#define ARRAY_SIZE 8

// プロトタイプ宣言
double getsum(int[], double[]);
double getave(double);
double getdist(double[], int[], double);

// グローバル変数で配列を定義

double class_value[] = {
	19.5,44.5,54.5,
	64.5,74.5,84.5,95.0
};

int frequency[] = {
	18,19,17,
	13,14,6,3
};

int main(void)
{

	double sum;
	double ave, dist;
	double standard_deviation;

	sum = getsum(frequency, class_value);		 // 合計値
	ave = getave(sum);							 // 平均値
	dist = getdist(class_value, frequency, ave); // 分散
	standard_deviation = sqrt(dist);			 // 標準偏差

	printf("合計値   : %2f\n", sum);
	printf("平均値   : %2f\n", ave);
	printf("分散     : %2f\n", dist);
	printf("標準偏差 : %2f\n", standard_deviation);
	return 0;
}

double getsum(int freq[], double val[])
{
	double sum = 0;

	for (int i = 0; i <= ARRAY_SIZE; i++)
		sum += val[i] * freq[i];

	return sum;
}

double getave(double sum)
{
	// 精度を保つためにdouble型でキャスト
	return sum / (double)SIZE;
}

double getdist(double val[], int freq[], double ave)
{
	double sum = 0;
	double result = 0;

	for (int i = 0; i <= ARRAY_SIZE; i++)
		sum += (val[i] - ave) * (val[i] - ave) * freq[i];
	// 精度を保つためにdouble型でキャスト
	result = sum / (double)SIZE;

	return result;
}

