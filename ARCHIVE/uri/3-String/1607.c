#include <stdio.h>
#include <string.h>
#include <math.h>

int i, j;
int qnt, len, dif, total;
char str1[10010], str2[10010];

int main (void){

	scanf("%d", &qnt);

	for (i = 0; i < qnt; i++){

		scanf("%s %s", str1, str2);

		len = strlen(str1);

		dif = total = 0;
		for (j = 0; j < len; j++){

			dif = (str2[j] - str1[j]);

			if (dif < 0)
				total += ('z' - 'a' + 1) + dif;
			else
				total += dif;

		}

		printf("%d\n", total);

	}

	return 0;
}
