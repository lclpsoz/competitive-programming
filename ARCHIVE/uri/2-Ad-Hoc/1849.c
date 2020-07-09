#include <stdio.h>

int a, b, c, d, big1, big2, sma1, sma2, aux, len, height;

int main (void){

	scanf("%d %d %d %d", &a, &b, &c, &d);

	if (b > a){

		aux = a;
		a = b;
		b = aux;

	}
	if (d > c){

		aux = c;
		c = d;
		d = aux;

	}
	big1 = a;
	big2 = c;
	sma1 = b;
	sma2 = d;

	len = sma1 + sma2; //Total lengh
	if (big1 > big2)
		height = big2;
	else
		height = big1;

	if (len > height)
		printf("%d\n", height*height);
	else
		printf("%d\n", len*len);

	return 0;
}
