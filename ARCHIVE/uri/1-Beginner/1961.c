#include <stdio.h>
#include <math.h>
int i;
int jump, amnt, num_1, num_2, dif, test = 1;

int main (void){

	scanf("%d %d", &jump, &amnt);

	scanf("%d", &num_1);
	for (i = 0; i < amnt - 1; i++){

		scanf("%d", &num_2);
		dif = fabs(num_1 - num_2);
		if (dif > jump)
			test = 0;

		num_1 = num_2;

	}

	if (test)
		printf("YOU WIN\n");
	else
		printf("GAME OVER\n");

	return 0;
}
