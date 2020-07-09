#include <stdio.h>
#include <math.h>

double ans, n;

int main (void){

	scanf("%lf", &n);

	ans = (pow(((1 + sqrt(5)) /	2 ), n) - pow(((1 - sqrt(5)) /	2 ), n))  / sqrt(5);

	printf("%.1lf\n", ans);

	return 0;
}
