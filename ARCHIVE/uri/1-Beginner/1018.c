#include <stdio.h>

void main(){
	
	int value, rest, b100, b50, b20, b10, b5, b2, b1;
	scanf("%d", &value);

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

	b1 = rest/1;
	rest = rest - (b1 * 1);

	printf("%d\n", value);
	printf("%d nota(s) de R$ 100,00\n", b100);
	printf("%d nota(s) de R$ 50,00\n", b50);
	printf("%d nota(s) de R$ 20,00\n", b20);
	printf("%d nota(s) de R$ 10,00\n", b10);
	printf("%d nota(s) de R$ 5,00\n", b5);
	printf("%d nota(s) de R$ 2,00\n", b2);
	printf("%d nota(s) de R$ 1,00\n", b1);
	
}