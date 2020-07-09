#include <stdio.h>

int i, j;
int amnt, num, test = 1, ones;
long long unsigned sum;

int main (void){

	scanf("%d", &amnt);

	while (i < amnt){

		i++;
		scanf("%d", &num);
		if (num == 1)
			ones++;
		sum += num;
		if (num % 2 == 0 && test){

			sum -= (i - ones);
			test = 0;
			j = i;

		}
		else if (test){

			sum--;
			j = i;

		}
	}

	printf("%d %lld\n", j, sum);

	return 0;
}
