#include <stdio.h>

int main(){
	
	int dist;
	double fuel, effic;

	scanf("%d%lf", &dist, &fuel);

	effic = dist / fuel;

	printf("%0.3lf km/l\n", effic);

	return 0;

}