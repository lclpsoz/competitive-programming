#include <stdio.h>
#include <math.h>

int i, j;
int qnt, qnt_stu, stu, val, min, pos;

int main (void){

	scanf("%d", &qnt);

	for (i = 0; i < qnt; i++){

		min = 1000000;
		pos = 0;
		scanf("%d %d", &qnt_stu, &val);
		for (j = 0; j < qnt_stu; j++){

			scanf("%d", &stu);

			if (fabs(stu - val) < min){

				min = fabs(stu - val);
				pos = j + 1;

			}
		}

		printf("%d\n", pos);
	}

	return 0;
}
