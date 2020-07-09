#include <stdio.h>

int main(){

	int i = 0;
	float n[2] = {-1, -1}, scr, avr = -1;
	
	while (avr == -1){

		scanf("%f", &scr);

		if (scr >= 0 && scr <= 10){
		
			n[i] = scr;
			i++;
		
		}
		else
			printf("nota invalida\n");

		if (n[0] != -1 && n[1] != -1){
	
			printf("media = %.2f\n", (float) (n[0] + n[1]) / 2);
			break;
	
		}
	}

	return 0;
}
