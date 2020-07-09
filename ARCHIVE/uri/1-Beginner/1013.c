#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int A, B, C, big;

	scanf("%d%d%d", &A, &B, &C);

	big = (A + B + abs(A - B)) / 2;
	big = (big + C + abs(big - C)) / 2;

	printf("%d eh o maior\n", big);

	return 0;

}