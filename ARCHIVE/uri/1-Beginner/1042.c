#include <stdio.h>
#include <stdlib.h>

int main(){

	int a, b, c, max, mid, min;
	scanf("%d%d%d", &a, &b, &c);

	max = (a + b + abs(a - b)) / 2;
	min = (a + b) - max;
	min = (min + c) - (min + c + abs(min - c)) / 2;
	max = (max + c + abs(max - c)) / 2;
	mid = (a + b + c) - min - max;

	printf("%d\n%d\n%d\n\n", min, mid, max);
	printf("%d\n%d\n%d\n", a, b, c);

	return 0;
}