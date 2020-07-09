#include <stdio.h>

int main(){

	int i;	
	double inc[5][2] = {
		{2000.01, 4}, {1200.01, 7}, {800.01, 10}, {400.01, 12}, {0, 15}};
	double test, salary, percent;
	scanf("%lf", &salary);

	for (i = 0; i < 5; ++i)	{
		
		if (salary >= inc[i][0]){

			percent = inc[i][1];
			break;

		}
	}

	printf("Novo salario: %.2lf\n", (salary * (1 + percent / 100)));
	printf("Reajuste ganho: %.2lf\n", (salary * (percent / 100)));
	printf("Em percentual: %.0lf %%\n", percent);

	return 0;
}