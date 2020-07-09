#include <stdio.h>

int main(){
	
	double area, pi, radius;

	scanf("%lf", &radius);
	pi = 3.14159;

	area = pi * radius * radius;

	printf("A=%.4lf\n", area);

	return 0;

}