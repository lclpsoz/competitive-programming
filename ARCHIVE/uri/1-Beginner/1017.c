#include <stdio.h>

int main(){
	
	int hours, avg;

	scanf("%d%d", &hours, &avg);

	printf("%0.3lf\n", (avg * hours) / 12.0);

	return 0;

}