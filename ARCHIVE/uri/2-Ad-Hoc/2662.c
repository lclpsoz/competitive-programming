#include <stdio.h>
#include <string.h>

typedef struct tom{

	char name[10];
	int list[10];
	int test;

} Tom;

int i, j, k;
int qnt, val, verif;
Tom arr[20];
int base[10] = {1, 3, 5, 6, 8, 10, 12};
char str[12][10] = {"do", "do#", "re", "re#", "mi", "fa", "fa#", "sol", "sol#", "la", "la#", "si"};

int main (void){

	for (i = 0; i < 12; i++){

		strcpy(arr[i].name, str[i]);
		for (j = 0; j < 7; j++){

			val = (base[j] + i) % 12;
			if (val == 0) val = 12;

			arr[i].list[j] = val;

		}

		arr[i].test = 1;
	}

	scanf("%d", &qnt);

	for (i = 0; i < qnt; i++){

		scanf("%d", &val);
		//printf("\n%d:\n", val);

		val %= 12;
		if (val == 0) val = 12;
		//printf("POS MOD: %d\n", val);

		for (j = 0; j < 12; j++){
			verif = 0;
			for (k = 0; k < 7; k++){
				//printf("%d == %d\n", val, arr[j].list[k]);

				if (val == arr[j].list[k]){
					//printf("%d %d\n", j, k);
					verif = 1;
				}
			}


			if (verif == 0)
				arr[j].test = 0;


		}
	}

	verif = 1;
	for (i = 0; i < 12; i++)
		if (arr[i].test){

			verif = 0;
			printf("%s\n", arr[i].name);
			break;

		}

	if (verif)
		printf("desafinado\n");

	return 0;
}
