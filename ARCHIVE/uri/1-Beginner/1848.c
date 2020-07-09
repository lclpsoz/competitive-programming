#include <stdio.h>
#include <math.h>

int i, j;
int sum;
char string[10];

int main (void){

	while (j < 3){

		scanf("%s", string);

		if (string[0] == 'c'){

			scanf("%s", string);
			j++;

			printf("%d\n", sum);
			sum = 0;

		}
		else
			for (i = 0; i < 3; i++)
				if (string[i] == '*')
					sum += pow(2, abs(i - 2));

	}

	return 0;
}
