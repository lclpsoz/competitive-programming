#include <stdio.h>

void bolha_dec (int size, int* array){

	int i, j;
	int aux, test;

	for (i = 0; i < size - 1; i++){

		test = 0;
		for (j =  i + 1; j < size; j++){

			if (array[i] < array[j]){

				test = 1;
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;

			}
		}

		if (!test)
			return;

	}
}



int main (void){

	int i;
	int grades_amnt, pos_amnt;
	int grades[101], pos;

	while (scanf("%d %d", &grades_amnt, &pos_amnt) != EOF){

		for (i = 0; i < grades_amnt; i++)
			scanf("%d", &grades[i]);

		bolha_dec(grades_amnt, grades);

		for (i = 0; i < pos_amnt; i++){

			scanf("%d", &pos);
			printf("%d\n", grades[pos - 1]);

		}
	}

	return 0;
}
