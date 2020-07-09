#include <stdio.h>

int i, j;
int size, forest[200][200], species[1000], x, y;

int main (void){

	scanf("%d", &size);

	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
			scanf("%d", &forest[i][j]);

	for (i = 0; i < size * 2; i++){

		scanf("%d %d", &x, &y);
		species[forest[x-1][y-1]-1] = 1;

	}

	x = 0;
	for (i = 0; i < 1000; i++)
		if (species[i])
			x++;

	printf("%d\n", x);

	return 0;
}
