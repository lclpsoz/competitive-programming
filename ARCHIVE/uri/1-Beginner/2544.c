#include <stdio.h>
#include <math.h>

int clones, times;

int main (void){

	while (scanf("%d", &clones) != EOF)
		printf("%.0lf\n", log2(clones));

	return 0;
}
