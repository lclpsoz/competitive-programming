#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+100, MAXM = 1e4, MAXH = 1e3;

int i, j, k, l;
int qnt, val;
int prim[MAXM];
bool sieve[MAXN];
int factors[MAXH][2]; //Saves the base and exp. from the factorization of the number
long long unsigned aux, divisors;

int main (){

	//Sieve of Eratosthenes
		//Boolean array
	for (i = 2; i <= MAXN/2; i++)
		if (!sieve[i])
			for (j = i+i; j < MAXN; j+=i)
				sieve[j] = true;

		//Array of primes
	i = 2;
	j = 0;
	while (i < MAXN){

		if (!sieve[i]) prim[j++] = i;
		i++;

	}

	/*for (i = 5700000; i < j; i++){

		printf("%d %d", i, prim[i]);
		if (i%4 == 0 || i%4 == 1 || i%4 == 2) printf("   ");
		else printf("\n");


	}*/

	scanf("%d", &qnt);

	for (i = 0; i < qnt; i++){

		scanf("%d", &val);

		//printf("val: %d\n", val);
		for (j = 0, k = 0; (prim[j]*prim[j]) <= val;){

			//printf("\t%d\n", prim[j]);

			if (!(val % prim[j])){

				val /= prim[j];

				if (factors[k][0] && factors[k][0] != prim[j]) k++;
				factors[k][0] = prim[j];
				factors[k][1]++;

			}
			else j++;

		}

		if (val > 1){

			if (factors[k][0] && factors[k][0] != val) k++;
			factors[k][0] = val;
			factors[k][1]++;

		}

		//for (j = 0; j <= k; j++)
		//	printf("%d %d\n", factors[j][0], factors[j][1]);

		divisors = 1;
		for (j = 0; j <= k; j++){

			aux = 0;
			for (l = 0; l <= factors[j][1]; l++)
				aux += (long long unsigned) pow(factors[j][0], l);

			divisors *= aux;
			factors[j][0] = factors[j][1] = 0;

		}

		printf("%llu\n", divisors);

	}

	return 0;
}
