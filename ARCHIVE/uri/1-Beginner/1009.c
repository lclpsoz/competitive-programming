#include <stdio.h>

int main(){

	char name;
	double salary, sales, paycheck;

	scanf("%s%lf%lf", &name, &salary, &sales);

	paycheck = salary + (sales * 0.15);

	printf("TOTAL = R$ %0.2lf\n", paycheck);

	return 0;
}