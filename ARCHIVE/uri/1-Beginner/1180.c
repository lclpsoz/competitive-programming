#include <stdio.h>

int i;
int size, min_pos, min_val;

int main (void){

	scanf("%d", &size);
	int array[size];

	scanf("%d", &array[0]);
	min_val = array[0];
	min_pos = 0;

	for (i = 1; i < size; i++){

		scanf("%d", &array[i]);

		if (min_val > array[i]){

			min_val = array[i];
			min_pos = i;

		}
	}

	printf("Menor valor: %d\n", min_val);
	printf("Posicao: %d\n", min_pos);

	return 0;
}
