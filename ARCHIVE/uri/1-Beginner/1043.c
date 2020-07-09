#include <stdio.h>

int main(){

	double A, B, C, test, per, area;
	scanf("%lf%lf%lf", &A, &B, &C);

	test = ((A + B) - C) * ((A + C) - B) * ((B + C) - A);

	if (test > 0){

		per = A + B + C;
		printf("Perimetro = %.1lf\n", per);

	}
	else{

		area = ((A + B) * C) / 2;
		printf("Area = %.1lf\n", area);

	}
	
	return 0;
}