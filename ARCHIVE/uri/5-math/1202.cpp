//Using rest of the number to get fib (mod 1500 fib cycles), pisano period
#include <bits/stdc++.h>

const int MAXS = 1e5, mod = 1500;

int i, j;
int qnt;
int fib[mod+1];
int rest, resp;
char str[MAXS];

int main (){

	fib[0] = 0;
	fib[1] = 1;
	for (i = 2; i < 1501; i++)
		fib[i] = (fib[i-1] + fib[i-2]) % 1000;

	scanf("%d", &qnt);
	for (i = 0; i < qnt; i++){

		scanf("%s", str);
		rest = 1;
		resp = 0;
		for (j = strlen(str)-1; j >= 0; j--){


			if (str[j]-'0') resp += rest;

			rest = (rest * 2) % mod;
			//printf("%d: %d\n", i, rest);

		}

		resp %= mod;
		//printf("%s %d\n", str, resp);
		printf("%03d\n", fib[resp]);

	}

	return 0;
}
