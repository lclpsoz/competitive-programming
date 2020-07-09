#include <stdio.h>

double w1, w2, rep, rm1, rm2, avr, sum, count, avr_final;

int main (void){

	scanf("%lf %lf %lf", &w1, &w2, &rep);

	while (w1){

		rm1 = w1 * (1 + (rep / 30));
		rm2 = w2 * (1 + (rep / 30));
		avr = (rm1 + rm2) / 2;

		//Sum and qnt of all tests
		sum += avr;
		count++;

		if (avr >= 1 && avr < 13)
			printf("Nao vai da nao\n");
		else if (avr >= 13 && avr < 14)
			printf("E 13\n");
		else if (avr >= 14 && avr < 40)
			printf("Bora, hora do show! BIIR!\n");
		else if (avr >= 40 && avr <= 60)
			printf("Ta saindo da jaula o monstro!\n");
		else if (avr > 60)
			printf("AQUI E BODYBUILDER!!\n");

		scanf("%lf %lf %lf", &w1, &w2, &rep);

	}

	avr_final = sum / count;

	if (avr_final > 40)
		printf("\nAqui nois constroi fibra rapaz! Nao e agua com musculo!\n");

	return 0;
}
