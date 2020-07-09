#include <stdio.h>
#include <math.h>

int i;
int coord[5];

int main (void){

	for (i = 0; i < 4; i++){

		scanf("%d", &coord[i]);
		coord[4] += coord[i];

	}

	while (coord[4]){

		if (coord[0] == coord[2] && coord[1] == coord[3])
			printf("0\n");
		else if (coord[0] == coord[2] || coord[1] == coord[3])
			printf("1\n");
		else if ((coord[0] - coord[1]) == (coord[2] - coord[3]))
			printf("1\n");
		else if((coord[0] + coord[1]) == (coord[2] + coord[3]))
			printf("1\n");
		else
			printf("2\n");

		coord[4] = 0;
		for (i = 0; i < 4; i++){

			scanf("%d", &coord[i]);
			coord[4] += coord[i];

		}
	}

	return 0;
}
