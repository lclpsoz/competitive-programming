#include <bits/stdc++.h>
using namespace std;

const int MAXPB = 1e6+10, MAXP = 1e5+10;

int i, j;
bool primes_sieve[MAXPB];
int primes[MAXP], unique_pr[50], fat[15];
long long unsigned int numb, resp;

int main (){

	//If FALSE -> PRIME
	for (i = 2; i < MAXPB; i++)
		if (!primes_sieve[i])
			for (j = i+i; j < MAXPB; j+=i)
				primes_sieve[j] = true;

	i = 0;
	for (j = 2; j < MAXPB; j++)
		if (!primes_sieve[j])
			primes[i++] = j;

	scanf("%llu", &numb);

	for (i = 0, j = 0; primes[i] && numb > 1;){

		if (numb % primes[i] == 0){

			numb /= primes[i];
			//printf("%llu\n", numb);
			if (!j)
				unique_pr[j++] = primes[i];
			else if (primes[i] != unique_pr[j-1])
				unique_pr[j++] = primes[i];

		}
		else
			i++;

	}
	if (numb > 1) unique_pr[j++] = numb;

	//printf("j = %d\n", j);

	fat[0] = 1;
	for (i = 1; i < 15; i++)
		fat[i] = fat[i-1] * i;

	for (i = 2; i <= j; i++){

		resp += (fat[j]) / (fat[j-i] * fat[i]);
		//printf("(%d / %d * %d)  %llu\n", j, j-i, i,resp);

	}

	printf("%llu\n", resp);

	//for (i = 0; i < j; i++)
		//printf("%d\n", unique_pr[i]);

	return 0;
}
