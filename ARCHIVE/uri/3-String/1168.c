#include <stdio.h>

int i, j;
int num, leds, qnt;
int arr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
char str[110];

int main (void){

	scanf("%d", &qnt);

	for (j = 0; j < qnt; j++){

		scanf("%s", str);

		leds = i = 0;
		while (str[i] != '\0')
			leds += arr[(str[i++] - '0')];

		printf("%d leds\n", leds);

	}

	return 0;
}
