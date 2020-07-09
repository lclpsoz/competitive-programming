#include <stdio.h>

int main(){
	
	int b100, b50, b20, b10, b5, b2, b1, c100, c50, c25, c10, c5;
	double value = 0, rest = 0, c1;

	scanf("%lf", &value);

	rest = value;

	b100 = rest/100;
	rest = rest - (b100 * 100);

	b50 = rest/50;
	rest = rest - (b50 * 50);

	b20 = rest/20;
	rest = rest - (b20 * 20);

	b10 = rest/10;
	rest = rest - (b10 * 10);

	b5 = rest/5;
	rest = rest - (b5 * 5);

	b2 = rest/2;
	rest = rest - (b2 * 2);

	c100 = rest/1;
	rest = rest - (c100 * 1);

	c50 = rest/0.50;
	rest = rest - (c50 * 0.50);

	c25 = rest/0.25;
	rest = rest - (c25 * 0.25);

	c10 = rest/0.10;
	rest = rest - (c10 * 0.10);

	c5 = rest/0.05;
	rest = rest - (c5 * 0.05);

	c1 = rest/0.01;
	rest = rest - (c1 * 0.01);

	printf("NOTAS:\n%d nota(s) de R$ 100.00\n", b100);
	printf("%d nota(s) de R$ 50.00\n", b50);
	printf("%d nota(s) de R$ 20.00\n", b20);
	printf("%d nota(s) de R$ 10.00\n", b10);
	printf("%d nota(s) de R$ 5.00\n", b5);
	printf("%d nota(s) de R$ 2.00\n", b2);
	printf("MOEDAS:\n%d moeda(s) de R$ 1.00\n", c100);
	printf("%d moeda(s) de R$ 0.50\n", c50);
	printf("%d moeda(s) de R$ 0.25\n", c25);
	printf("%d moeda(s) de R$ 0.10\n", c10);
	printf("%d moeda(s) de R$ 0.05\n", c5);
	printf("%0.0lf moeda(s) de R$ 0.01\n", c1);

	return 0;
}