#include <stdio.h>

int i;
char string[27];
int blinked, bulb;

int main (void){

	while (scanf("%s", string) != EOF){

		scanf("%d", &blinked);

		for (i = 0; i < blinked; i++){

			scanf("%d", &bulb);
			printf("%c", string[bulb - 1]);

		}

		printf("\n");

	}

	return 0;
}
