#include <stdio.h>

int test (int row, int col, int matrix[1000][1000], int pos_x, int pos_y){

	int i, j;

	for (i = pos_x; i < pos_x + 3; i++)
		for (j = pos_y; j < pos_y + 3; j++)
			if (i == pos_x + 1 && j == pos_y + 1 && matrix[i][j] != 42)
				return 0;
			else if ((i != pos_x + 1 || j != pos_y + 1) && matrix[i][j] != 7)
				return 0;

	return 1;
}

int main (void){

	int i, j;
	int row, col, tabl[1000][1000], x, y;

	scanf("%d %d", &row, &col);

	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			scanf("%d", &tabl[i][j]);

	for (i = 0; i < row - 2; i++)
		for (j = 0; j < col - 2; j++)
			if (tabl[i][j] == 7  && test(row, col, tabl, i, j)){

				x = i + 2;
				y = j + 2;
				break;

			}

	printf("%d %d\n", x, y);

	return 0;
}

