#include <stdio.h>

int i;
int a, b;
long long int fat[21];

int main (void){

	fat[0] = 1;	//1! = 1
	for (i = 1; i < 21; i++)
		fat[i] = fat[i-1] * i;

	while (scanf("%d %d", &a, &b) != EOF)
		printf("%lld\n", fat[a] + fat[b]);

	return 0;
}
