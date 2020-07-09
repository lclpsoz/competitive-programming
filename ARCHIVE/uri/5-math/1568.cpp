//To count the amount sum of sequences of integer that result in a specific integer n: Count the amount of odd DIVISORS 9 = 3 * 3 * 1 → 9 have 2 sequences, +1 counting it self (a sequence with 1 value)
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e7+1000, MAXZ = 2e6;

int i, j, k, l;
int resp;
long long n;
bool primes[MAXN];
long long primes_lst[MAXZ];
int factors[1000];

int main (){

	for (i = 2; (2*i) <= MAXN; i++)
		if (!primes[i]){

			for (j = 2*i; j < MAXN; j += i) primes[j] = true;

		}

	i = 2, k = 0;
	while (i < MAXN){

		if(!primes[i])
			primes_lst[k++] = i;
		i++;

	}

	while (scanf("%lld", &n) != EOF){

		//printf("  %lld\n", n);

		i = 0, l = 0;
		while (primes_lst[i] * primes_lst[i] <= n || primes_lst[i] == n){


			if (!(n % primes_lst[i])){


				n /= primes_lst[i];
				if (primes_lst[i] != 2) factors[l]++;
				//printf("\n\t%lld\t%lld\n", n, primes_lst[i]);

			}
			else{

			   i++;
			   if (factors[l]) l++;

			}

		}
		//printf("%lld\n", n);
		if (factors[l]) l++;
		if (n > 1 && n % 2 == 1) factors[l++]++;

		resp = 1;
		for (i = 0; i < l; i++){

			//printf("fac: %d\n", factors[i]+1);
			resp *= factors[i]+1;
			factors[i] = 0;

		}

		printf("%d\n", resp);

	}

	return 0;
}
