#include <stdio.h>
#include <math.h>

int a, b, c;

int main (void){

	scanf("%d %d %d", &a, &b, &c);

	if (a == b || a == c || b == c || a == b + c || b == a + c || c == a + b)
		printf("S\n");
	else
		printf("N\n");

	return 0;
}
