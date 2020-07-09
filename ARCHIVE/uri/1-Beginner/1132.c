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

	for (i = x; i <= y; i++)
		if (i % 13 != 0)
			sum += i;

	printf("%d\n", sum);

	return 0;
}
