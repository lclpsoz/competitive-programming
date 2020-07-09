#include <stdio.h>

int i;
int amnt;
char str[100];

int main (void){

	scanf("%d", &amnt);

	for (i = 0; i < amnt; i++)
		scanf(" %[^\n]s", str);

	printf("Ciencia da Computacao\n");

	return 0;
}
