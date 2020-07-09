#include <stdio.h>

float test(){
	
	int run = 0;
	
	while (run != 1 && run != 2){
		
		printf("novo calculo (1-sim 2-nao)\n");
		scanf("%d", &run);

	}

	return run;
}

int main(){

	int i = 0;
	float n[2] = {-1, -1}, scr, run = 1;
	
	while (run == 1){

		scanf("%f", &scr);

		if (scr >= 0 && scr <= 10){
		
			n[i] = scr;
			i++;
		
		}
		else
			printf("nota invalida\n");

		if (n[0] != -1 && n[1] != -1){
	
			printf("media = %.2f\n", (float) (n[0] + n[1]) / 2);
			
			run = test();
			n[0] = -1;
			n[1] = -1;
			i = 0;

		}
	}

	return 0;
}
