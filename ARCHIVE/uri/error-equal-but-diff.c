//INPUT: 2 1 8 2 8.1 OUTPUT: (CORRECT) 2, OUTPUT: (REAL) 1

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

	int amount, x, bigger_reg, odd_reg, even_reg, reg;
	double odd_score, even_score, bigger_score, score;
	scanf("%d", &amount);

	for (x = 0; x < amount; x++){

		scanf("%d %lf", &reg, &score);

		if ((x + 1) % 2 == 1){

			odd_reg = reg;
			odd_score = score;

			bigger_score = (odd_score + bigger_score + fabs(odd_score - bigger_score)) / 2;
			if (bigger_score == odd_score){

				bigger_reg = odd_reg;

			}
		}
		else{
			printf("even");
			even_reg = reg;
			even_score = score;

			bigger_score = (even_score + bigger_score + fabs(even_score - bigger_score)) / 2;
			printf("%lf == %lf\nreg: %d\n", bigger_score, even_score, even_reg);
			if (bigger_score == even_score){

				bigger_reg = even_reg;

			}
		}
	}

	if (bigger_score < 8){

		printf("Minimum note not reached\n");

	}
	else{

		printf("%d\n", bigger_reg);

	}

	return 0;
}