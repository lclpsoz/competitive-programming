#include <stdio.h>

int i;
int grades, grade, workload, sum_workload;
double result;

int main (void){

	while(scanf("%d", &grades) != EOF){

		for (i = 0; i < grades; i++){

			scanf("%d %d", &grade, &workload);

			result += (grade * workload);
			sum_workload += workload;

		}

		result /= sum_workload * 100;
		printf("%.4lf\n", result);

		result = 0;
		sum_workload = 0;
	}

	return 0;
}
