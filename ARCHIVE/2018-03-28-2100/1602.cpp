#include <bits/stdc++.h>
using namespace std;

const int MAXM = 2e6+100;

int n, k;
long long aux;
int small_primes[] = {2, 3, 5, 7, 11, 13, 17, 19};
bool small_pr[30];
bool not_prime[MAXM];
bool is_hyper[MAXM];
int hyper[MAXM];

int main ()
{
	for (int i : small_primes)
		small_pr[i] = true;

	not_prime[1] = true;
	int i;
	for (i = 2; i*i < MAXM; i++)
		if (!not_prime[i]) {
			for (int j = i*i; j < MAXM; j+=i)
				not_prime[j] = true;
			aux = 1;
			k = 0;
			while (aux < MAXM) {
				if (small_pr[k+1])
					is_hyper[aux] = true;
				aux *= i;
				k++;
			}
		}

	for (int i = 1; i < MAXM; i++)
		hyper[i] = (hyper[i-1])+(is_hyper[i] || !not_prime[i]);

	while (scanf ("%d", &n) != EOF)
		printf ("%d\n", hyper[n]);

	return 0;
}
