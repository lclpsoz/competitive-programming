#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e6+10;
const int mod = 1300031;

long long i;
int qnt;
int qnt_vars, sum;
int fat[MAXN];

int mod_inv (long long n){

	long long exp = mod-2; //Fermat and -1 to take the inverse, so -2
	long long rest = 1;

	while (exp > 1){

		if (exp % 2 == 1){

			rest *= n;
			rest %= mod;
			exp--;

		}

		n *= n;
		n %= mod;
		exp /= 2;

	}

	n *= rest;
	n %= mod;
	return n;

}

int main (){

	int k, n;
	long long x, y, z;

	fat[0] = 1;
	fat[1] = 1;
	for (i = 2; i <= MAXN; i++){

		fat[i] = (((long long)fat[i-1] * i) % mod);

	}

	scanf("%d", &qnt);

	for (i = 0; i < qnt; i++){

		scanf("%d %d", &qnt_vars, &sum);
		k = qnt_vars, n = sum;
		x = fat[n + k-1], y = fat[n], z = fat[k-1];

		//printf("%lld %lld %lld\n", x, y, z);
		//printf("%lld %lld %lld\n", x, y, z);
		printf("%lld\n", ((x * mod_inv(y) * mod_inv(z)) % mod));

	}

	return 0;
}
