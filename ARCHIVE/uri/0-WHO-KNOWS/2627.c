#include <stdio.h>

int i, j;
char c;
int arr[27];
int str_size, value, sum, maxi, val;

int main (void){

	while (scanf("%d %d", &str_size, &value) != EOF){


		for (i = 0; i < str_size; i++){

			scanf(" %c", &c);
			//printf("%c\n", c);
			val = 26 - (c - 'a');
			for (j = val, maxi = 0; j < 27; j++){

				sum = val + arr[j];
				if (sum > maxi)
					maxi = sum;

			}
			arr[val] = maxi;

		}

		for (i = 0, maxi = 0; i < 27; i++){

			if (arr[i] > maxi) maxi = arr[i];
			//printf("%d ", arr[i]);
			arr[i] = 0;

		}
		//printf("\n");

		//printf("%d\n", maxi_sum);

		if (maxi >= value)
			printf("Aceita\n");
		else
			printf("Rejeita\n");

	}

	return 0;
}

