#include <bits/stdc++.h>
using namespace std;

int i;
int qnt;
double price, weight, price_t, weight_t;
char c;

int main (){

	scanf("%d", &qnt);
	for (i = 0; i < qnt; i++){

		scanf("%lf\n", &price);

		weight = 1;
		c = getchar();
		while (c != EOF && c != '\n'){

			if (c == ' ') weight++;
			c = getchar();

		}

		printf("day %d: %.0lf kg\n", i+1, weight);
		weight_t += weight;
		price_t += price;

	}

	printf("%0.2lf kg by day\n", weight_t / (double) qnt);
	printf("R$ %0.2lf by day\n", price_t / (double) qnt);

	return 0;
}
