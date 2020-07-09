#include <bits/stdc++.h>
using namespace std;

const int MAXP = 1e6+10;

int i, j, k;
//In factors[MAXP] will be store the expoetns of the factorization of all populations, will be compare to get the larger to use that to calculate the LCM, divide it by the maxi iteration, use floor to get the larger possible multiple, with that will calculate the larger value to maximize that last LCM
int qnt, maxi, factors[MAXP], factors_obj[MAXP], primes[MAXP], aux, factor;
long long unsigned int popu, lcm_bef, multi_obj, resp;
bool test;

void factor_func (int *prim, int *fact, long long unsigned *value){

	for (j = 0, factor = 0; prim[j]*prim[j] <= *value && *value > 1;){

		while (*value % prim[j] == 0){

			*value /= prim[j];
			factor++;

		}
		if (factor > fact[prim[j]])
			fact[prim[j]] = factor;
		factor = 0;

		j++;

	}

	if (*value > 1)
		if (1 > fact[*value])
			fact[*value] = 1;
}

int main (){

	for (i = 2, k = 0; i < MAXP; i++){

		test = true;
		for (j = 2; j*j <= i; j++)
			if (i % j == 0){

				test = false;
				break;

			}

		if (test)
			primes[k++] = i;

	}
	//printf("k: %d\nMAX: %d\n\n", k, primes[k-1]);

	scanf("%d %d", &qnt, &maxi);

	for (i = 0; i < qnt; i++){

		scanf("%llu", &popu);
		factor_func (primes, factors, &popu);

	}

	//Start from to because it's the first prime
	//printf("FACTORS\t| EXP.\n");
	for (i = 2, lcm_bef = 1; i < MAXP; i++)
		if (factors[i]){

			//printf("%d\t| %d\n", i, factors[i]);
			lcm_bef *= pow(i, factors[i]);

		}

	multi_obj = floor(maxi / lcm_bef);
	//printf("\nLCM_BEF: %llu\n", lcm_bef);
	//printf("MULTI_OBJ: %llu\n", multi_obj);

	factor_func (primes, factors_obj, &multi_obj);

	for (i = 2, resp = 1; i < MAXP; i++)
		if (factors_obj[i])
			resp *= pow(i, (factors_obj[i] + factors[i]));

	printf("%llu\n", resp);

	return 0;
}
