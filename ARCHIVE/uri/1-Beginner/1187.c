//Top area

#include <stdio.h>

int i, j;
double array[12][12], sum, rsp;
char opt;

int main (void){

	scanf("%c", &opt);

	for (i = 0; i < 12; i++)
		for (j = 0; j < 12; j++){

			scanf("%lf", &array[i][j]);

			if ((i + j < 11) && (j > i))
				sum += array[i][j];

		}

	if (opt == 'S')
		printf("%.1lf\n", sum);
	else
		printf("%.1lf\n", sum / 30);

	return 0;
}
