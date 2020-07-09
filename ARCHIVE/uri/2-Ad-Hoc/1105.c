#include <stdio.h>

int i;
int bank_qnt, deb_qnt, res[20];
int pag, rec, tranf;

int main (void){

	scanf("%d %d", &bank_qnt, &deb_qnt);

	while (bank_qnt){

		for (i = 0; i < bank_qnt; i++)
			scanf("%d", &res[i]);

		for (i = 0; i < deb_qnt; i++){

			scanf("%d %d %d", &pag, &rec, &tranf);

			res[pag - 1] -= tranf;
			res[rec - 1] += tranf;

		}

		for (i = 0; i < bank_qnt; i++)
			if (res[i] < 0){

				printf("N\n");
				i = bank_qnt + 1;

			}

		if (i == bank_qnt)
			printf("S\n");

		scanf("%d %d", &bank_qnt, &deb_qnt);
	}

	return 0;
}
