#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned llu;

const int MAXN = 1e6+10, MAXP = 1e5;

int i, j, k;
int prime[MAXP];
bool not_prime[MAXN];
llu n;

int main (){

	//Sieve of Eratosthenes adapted to the question
	for (i = 2; i*i < MAXN; i++){

		if (!not_prime[i]){

			for (j = i*i; j < MAXN; j+=i)
				not_prime[j] = true;

			prime[k++] = i;

		}

	}

	//Saving odd primes
	for (i = i-1; i < MAXN; i++)
		if (!not_prime[i])
			prime[k++] = i;


	while (scanf("%llu", &n), n){

		printf("%llu = ", n);

		//Factorization adapted to the question
		for (i = 1, j = 0; j < 2; i++){

			if (!(n % prime[i])){

				printf("%d x ", prime[i]);
				n /= prime[i];
				j++;

			}

		}
		printf("%llu\n", n);

	}

	return 0;
}
