#include <stdio.h>

int i, j;
int n, m, dif, used, count, bill[6] = {2, 5, 10, 20, 50, 100};

int main (void){

	scanf("%d %d", &n, &m);

	while (n != 0){

		dif = m - n;

		for (j = 0; j < 2; j++)
			for (i = 5; i >= 0; i--)
				if (dif >= bill[i] && used != bill[i]){

					dif -= bill[i];
					used = bill[i];
					count++;
					break;

				}

		if (dif == 0 && count == 2)
			printf("possible\n");
		else
			printf("impossible\n");

		used = 0;
		count = 0;
		scanf("%d %d", &n, &m);
	}

	return 0;
}
