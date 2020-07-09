#include <stdio.h>

int i, j;
double array[12][12], sum, res;
int row;
char opr;

int main (void){

	scanf("%d", &row);
	scanf(" %c", &opr);

	for (i = 0; i < 12; i++)
		for (j = 0; j < 12; j++)
			scanf("%lf", &array[i][j]);

	for (i = 0; i < 12; i++){

		sum += array[row][i];

		if (opr == 'S')
			res = sum;
		
		if (opr == 'M')
			res = sum / 12;

	}

	printf("%.1lf\n", res);

	return 0;
}
