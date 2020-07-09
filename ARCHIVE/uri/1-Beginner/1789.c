#include <stdio.h>

int i;
int amnt, var, max;

int main (void){

	while (scanf("%d", &amnt) != EOF){

		for (i = 0; i < amnt; i++){

			scanf("%d", &var);
			if (var > max)
				max = var;

		}

		if (max < 10)
			printf("1\n");
		else if (max >= 10 && max < 20)
			printf("2\n");
		else if (max >= 20)
			printf("3\n");

		max = 0;

	}

	return 0;
}
