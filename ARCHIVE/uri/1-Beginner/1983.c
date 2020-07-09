#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define new_max(x, y) ((x) >= (y)) ? (x) : (y);
#define new_min(x, y) ((x) <= (y)) ? (x) : (y);

int main(){

	int amount, x, bigger_reg, odd_reg, even_reg, reg;
	double odd_score, even_score, bigger_score, score;
	scanf("%d", &amount);

	for (x = 0; x < amount; x++){

		scanf("%d %lf", &reg, &score);
		score = (int)(score * 10);
		score /= 10;
		if ((x + 1) % 2 == 1){

			odd_reg = reg;
			odd_score = score;

			bigger_score = new_max(bigger_score, odd_score);
			if (bigger_score == odd_score){

				bigger_reg = odd_reg;

			}
		}
		else{

			even_reg = reg;
			even_score = score;

			bigger_score = new_max(bigger_score, even_score);
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