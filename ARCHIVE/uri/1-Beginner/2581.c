#include <stdio.h>

int i;
int runs;
char entry[2000];

int main (void){

	scanf("%d", &runs);

	for (i = 0; i < runs; i++){

		scanf(" %[^\n]", entry);
		printf("I am Toorg!\n");

	}

	return 0;
}
