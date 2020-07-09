#include <stdio.h>

int i;
int amnt;
char string[34] = "LIFE IS NOT A PROBLEM TO BE SOLVED";

int main (void){

	scanf("%d", &amnt);

	for (i = 0; i < amnt; i++)
		printf("%c", string[i]);

	printf("\n");

	return 0;
}
