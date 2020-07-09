#include <stdio.h>
#include <math.h>

double PI = 3.14;
double vol, diam, height, area;

int main (void){

	while (scanf("%lf %lf", &vol, &diam) != EOF){

		//vol = 2 * PI * (diam / 2)^2 * height;
		height = vol / (PI * pow(diam / 2, 2));
		area = PI * pow((diam / 2), 2);

		printf("ALTURA = %.2lf\n", height);
		printf("AREA = %.2lf\n", area);

	}

	return 0;
}
