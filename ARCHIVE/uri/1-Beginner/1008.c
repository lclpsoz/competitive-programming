#include <stdio.h>

int main(){

	int numb, hours;
	double salary, paycheck;

	scanf("%d%d%lf", &numb, &hours, &salary);

	paycheck = hours * salary;

	printf("NUMBER = %d\n", numb);
	printf("SALARY = U$ %0.2lf\n", paycheck);

	return 0;
}