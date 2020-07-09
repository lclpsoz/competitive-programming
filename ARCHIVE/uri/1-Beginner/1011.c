#include <stdio.h>

int main(){
	
	double vol, pi, radius;

	scanf("%lf", &radius);
	pi = 3.14159;

	vol = (4.0/3) * pi * radius * radius * radius;

	printf("VOLUME = %.3lf\n", vol);

	return 0;

}