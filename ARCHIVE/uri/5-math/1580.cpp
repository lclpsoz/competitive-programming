#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned llu;
const int MOD = 1e9+7, MAXS = 1e3+10, MAXN = 30, MAXM = 1e3+10;

int i;
llu total, divisor, resp; //Total amount of letters; Divisor of the expression;
llu fat[MAXM];
char str[MAXS];
short int arr[MAXN]; //Amount of letters

llu inv_mod (int a){

	llu rest = 1, exp = MOD-2, base = a, inv;

	while (exp > 1){

		if (exp % 2 == 1){

			rest *= base;
			rest %= MOD;
			exp--;

		}

		exp /= 2;
		base = (base*base) % MOD;

	}

	inv =  (base * rest) % MOD;
	return inv;

}

int main (){

	fat[0] = 1;
	for (i = 1; i < MAXM; i++)
		fat[i] = (fat[i-1] * (llu)i) % MOD;

	while (scanf("%s", str) != EOF){

		total = 0;
		for (i = 0; str[i] != '\0'; i++)
			arr[str[i]-'A']++;

		divisor = 1;
		for (i = 0; i < 30; i++)
			if (arr[i]){

				total += arr[i];
				divisor = (divisor*fat[arr[i]]) % MOD;

			}

		total = fat[total];

		//printf("\n%llu %llu\n", total, divisor);

		resp = (total * inv_mod(divisor)) % MOD;

		printf("%llu\n", resp);

		for (i = 0; i < 30; i++) arr[i] = 0;

	}

	return 0;
}
