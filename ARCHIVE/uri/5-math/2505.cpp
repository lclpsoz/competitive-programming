#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned llu;
const int MOD = 1e7;

int i;
llu value;
llu base, expoent;
llu arr[30][2]; //Store previous powers of power of 2, ex: pos. 0 is x^2^0 → x^1, pos. 1 is x^2^1 → x^2 and so on

int main (){

	while (scanf("%llu", &value) != EOF){

		expoent = 1;
		base = value;

		i = 0;
		while (expoent*2 <= value){

			arr[i][0] = expoent;
			arr[i++][1] = base;
			base = (base * base) % MOD;
			expoent *= 2;

		}
		arr[i][0] = expoent;
		arr[i][1] = base;

		while (expoent < value){

			while (expoent+arr[i][0] > value) i--;

			expoent += arr[i][0];
			base = (base * arr[i][1]) % MOD;

		}

		if (base >= value) base -= value;
		else base = 1;
		//printf("%llu %llu\n", expoent, base);

		if (base % (int)pow(10, (floor(log10(value))+1))) printf("NAO\n");
		else printf("SIM\n");

	}

	return 0;
}
