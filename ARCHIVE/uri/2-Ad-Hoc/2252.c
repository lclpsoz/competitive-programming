#include <stdio.h>
#include <math.h>

int i, j;
int size, pos, count;
double oil[15], max;
char key[15];

int main (void){

	while (scanf("%d", &size) != EOF){

		key[size] = '\0';
		for (i = 0; i < 10; i++)
			scanf("%lf", &oil[i]);

		for (i = 0; i < size; i++){

			max = -1;
			for (j = 0; j < 10; j++)
				if (oil[j] > max){

					max = oil[j];
					pos = j;

				}

			key[i] = '0' + pos;
			oil[pos] = -1;

		}

		printf("Caso %d: %s\n", ++count, key);

	}

	return 0;
}
