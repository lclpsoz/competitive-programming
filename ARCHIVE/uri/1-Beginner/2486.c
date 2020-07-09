#include <stdio.h>
#include <string.h>

int i, j;
int runs, food_qnt, vit;
char food_name[20];
int food_values[7] = {120, 85, 85, 70, 56, 50, 34};
char food_names[7][20] = {	"suco de laranja", 	"morango fresco",
							"mamao",			"goiaba vermelha",
							"manga",			"laranja",
							"brocolis"};

int main (void){

	scanf("%d", &runs);

	while (runs != 0){

		for (i = 0; i < runs; i++){

			scanf("%d ", &food_qnt);
			scanf("%[^\n]", food_name);
			for (j = 0; j < 7; j++)
				if (!strcmp(food_name, food_names[j]))
					vit += food_values[j] * food_qnt;

		}

		if (vit < 110)
			printf("Mais %d mg\n", 110 - vit);
		else if (vit > 130)
			printf("Menos %d mg\n", vit - 130);
		else
			printf("%d mg\n", vit);
		vit = 0;

		scanf("%d", &runs);

	}

	return 0;
}
