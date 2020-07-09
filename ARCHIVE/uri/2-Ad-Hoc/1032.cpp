#include <bits/stdc++.h>
using namespace std;

const int MAXP = 4e4, MAXN = 4e3;

int i, j, k, l;
int qnt, primes_bo[MAXP], primes[MAXN], arr[MAXN], rest;

int main (void){

	// Sieve of Eratosthenes
	for (i = 2; i < MAXP; i++)
		if (!primes_bo[i])	//Primes (0)
			for (j = i*2; j < MAXP; j+= i)
				primes_bo[j] = 1;	//Not primes (1)

	// Saving primes
	for (i = 0, j = 2; i < MAXN; i++){

		while(primes_bo[j]) j++;
		primes[i] = j++;

	}

	scanf("%d", &qnt);

	while (qnt){

		for (i = 0; i < qnt; i++)
			arr[i] = i+1;

		j = i = 0;
		while (j < qnt-1){

			/*for (l = 0; l < qnt; l++)
				printf("%d ", arr[l]);
			printf("\n");*/
			k = 0;
			rest = primes[j] % (qnt - j);
			if (!rest) rest = qnt - j;
			//printf("%d\n", rest);
			while (!arr[i] || k < rest-1){

				//printf("BEF: k: %d\ti: %d\tarr: %d\n", k, i, arr[i]);

				if (arr[i]) k++;
				i++;
				if (i == qnt) i = 0;
				//printf("AFT: k: %d\ti: %d\tarr: %d\n", k, i, arr[i]);

			}

			arr[i++] = 0;
			if (i == qnt) i = 0;
			j++;

		}
		for (k = 0; k < qnt; k++)
			if (arr[k]) printf("%d", arr[k]);
		printf("\n");


		scanf("%d", &qnt);
	}

	return 0;
}
