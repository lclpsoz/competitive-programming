#include <stdio.h>
#include <math.h>

int i, j;
int qnt, max_div;
long long unsigned int worker, sum, twos;

int main (void){

	scanf("%d", &qnt);

	for (j = 0; j < qnt; j++){

		scanf("%llu", &worker);

		max_div = sqrt(worker) + 1;
		//printf("%d\n", max_div);

		twos = 0;
		sum = 1;
		while (worker > 1){

			printf("st:\t%llu|%llu\n", sum,worker);
			while (worker % 2 == 0){

				twos += 1;
				worker /= 2;

			}
			for (i = 3; i <= max_div; i+=2){
				printf("i(%d)\t%llu|%llu\n", i, sum,worker);
				if (worker % i == 0){

					sum += i;
					worker /= i;
					break;

				}
			}
			if (i > max_div && worker > 1){

				sum += worker;
				worker = 1;

			}
		}

		for (i = 1; i <= twos; i++)
			sum += pow(2, i);

		printf("%llu\n", sum);

	}

	return 0;
}
