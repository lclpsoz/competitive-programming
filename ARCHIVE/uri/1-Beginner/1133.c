#include <stdio.h>

int i;
int x, y, tmp, sum;

int main(void){

	scanf("%d%d", &x, &y);

	if (x > y){

		tmp = x;
		x = y;
		y = tmp;

	}

	for (i = (x + 1); i < y; i++)
		if (i % 5 == 2 || i % 5 == 3)
			printf("%d\n", i);

	return 0;
}
