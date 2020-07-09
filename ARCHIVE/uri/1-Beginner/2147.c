#include <stdio.h>
#include <string.h>

int i, j;
int c;
char str[10001];

int main (void){

	scanf("%d", &c);

	for (i = 0; i < c; i++){

		scanf("%s", str);

		for (j = 0; j < 10000; j++)
			if (str[j] == '\0')
				break;

		printf("%.2lf\n", j / 100.0);
	}

	return 0;
}
