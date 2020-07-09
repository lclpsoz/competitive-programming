#include <stdio.h>

int i;
double runs, ser_amt, ser_suc, blc_amt, blc_suc, att_amt, att_suc;
double total[3], sucess[3];
char name[1000];

int main (void){

	scanf("%lf", &runs);

	for (i = 0; i < runs; i++){

		scanf("%s", name);

		scanf("%lf %lf %lf", &ser_amt, &blc_amt, &att_amt);
		scanf("%lf %lf %lf", &ser_suc, &blc_suc, &att_suc);

		total[0] += ser_amt;
		total[1] += blc_amt;
		total[2] += att_amt;

		sucess[0] += ser_suc;
		sucess[1] += blc_suc;
		sucess[2] += att_suc;

	}

	printf("Pontos de Saque: %.2lf %%.\n", (sucess[0] / total[0]) * 100);
	printf("Pontos de Bloqueio: %.2lf %%.\n", (sucess[1] / total[1]) * 100);
	printf("Pontos de Ataque: %.2lf %%.\n", (sucess[2] / total[2]) * 100);

	return 0;
}
