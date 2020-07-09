#include <stdio.h>

int runs, qnt, steps, end, mans[10100], mans_st, mans_end;

void circle (int pos){

	int i, j;

	for (i = 0, j = 0; j < pos || !mans[i]; i++){

		if (mans[i])
			j++;

	}

	mans[i] = 0;

	/*j = mans_st;
	if (!pos){

		while (!mans[j])
			j++;
		mans_st = j;

	}

	j = mans_end;
	if (pos == end){

		while (!mans[j])
			j--;
		mans_end = j;

	}*/

	end--;

}

int main (void){

	int i, j, k, l;

	scanf("%d", &runs);

	for (i = 0; i < runs; i++){

		scanf("%d %d", &qnt, &steps);
		end = qnt - 1;
		mans_st = 0;
		mans_end = end;

		for (j = 0; j < qnt; j++)
			mans[j] = j + 1;

		/*for (k = 0, l = 0; k < qnt; k++)
			if (mans[l] == k + 1){

				printf("%d ", k + 1);
				l++;

			}
			else if (k >= 9)
				printf("__ ");
			else
				printf("_ ");
		printf("\n");*/
		/*for (k = 0; k < qnt; k++)
			printf("%d ", mans[k]);
		printf("\n");*/
		for (j = (steps - 1); end; j+= (steps - 1)){

			while (j > end)
				j = j - end - 1;

			circle (j);


			/*printf("pos: %d\t| end: %d\t| ", j, end);
			for (k = 0; k <= end; k++)
				printf("%d ", mans[k]);
			printf("\n");*/

			/*for (k = 0; k < qnt; k++)
				printf("%d ", mans[k]);
			printf("\n");*/
		}

		for (j = 0; j < qnt; j++)
			if (mans[j])
				break;

		printf("Case %d: %d\n", i + 1, mans[j]);

	}

	return 0;
}
