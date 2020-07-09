#include <stdio.h>

int hr, min, hr_del, min_del;

int main (void){

	while (scanf("%d:%d", &hr, &min) != EOF){

		hr_del = (hr + 1) - 8;
		if (hr_del >= 0){

			min_del = min + (hr_del * 60);
			printf("Atraso maximo: %d\n", min_del);

		}
		else
			printf("Atraso maximo: 0\n");

	}

	return 0;
}

