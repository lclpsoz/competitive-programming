#include <stdio.h>
#include <math.h>

int i, j;
int rows, col;
int temp; //Temporary variable
int row_targ, col_targ;	//Target position
int row_pos, col_pos;	//Player position

int main (void){

	while (scanf("%d %d", &rows, &col) != EOF){

		for (i = 0; i < rows; i++)
			for (j = 0; j < col; j++){

				scanf("%d", &temp);

				if (temp == 2){

					row_targ = i;
					col_targ = j;

				}
				else if (temp == 1){

					row_pos = i;
					col_pos = j;

				}
				temp = 0;

			}

		printf("%.0f\n", fabs(row_pos - row_targ) + fabs(col_pos - col_targ));

	}

	return 0;
}

