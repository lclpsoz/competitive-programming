#include <stdio.h>

int i, j;
int runs;
double lvl, scr, scr_sum, scr_min = 10.1, scr_max = -0.1;
char name[100];

int main (void){

	scanf("%d", &runs);

	for (i = 0; i < runs; i++){

		scanf("%s", name);
		scanf("%lf", &lvl);

		for (j = 0; j < 7; j++){

			scanf("%lf", &scr);
			if (scr < scr_min)
				scr_min = scr;
			if (scr > scr_max)
				scr_max = scr;

			scr_sum += scr;

		}

		scr_sum -= scr_min + scr_max;
		scr_sum *= lvl;

		printf("%s %.2lf\n", name, scr_sum);
		scr_sum = 0;
		scr_min = 10.1;
		scr_max = -0.1;

	}

	return 0;
}
