#include <stdio.h>

int i;
double bef, days, aft, min_days, a, b, mmc;
int pages;

int main (void){

	scanf("%lf", &bef);

	while (bef){

		scanf("%lf %lf", &days, &aft);

		a = aft;
		b = bef;
		while (a != b)
			if (a > b)
				b += bef;
			else
				a += aft;

		mmc = a;

		min_days = (mmc / bef) - (mmc / aft);

		pages = (days / min_days) * mmc;
		if (pages == 1)
			printf("1 pagina\n");
		else
			printf("%d paginas\n", pages);

		scanf("%lf", &bef);
	}

	return 0;
}
