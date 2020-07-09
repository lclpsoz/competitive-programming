#include <stdio.h>

int main(){

	double numb, sum, avrg;
	int count, i;
	for (i = 0; i < 6; ++i){
	 	
	 	scanf("%lf", &numb);

	 	if (numb > 0){

	 		count++;
	 		sum += numb;
	 	
	 	}
	 }

	avrg = sum / count;
	printf("%d valores positivos\n%.1lf\n", count, avrg);

	return 0;
}