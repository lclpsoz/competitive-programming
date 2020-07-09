#include <bits/stdc++.h>
using namespace std;

long long unsigned a, b, i, resp;

int main (){

	scanf("%llu %llu", &a, &b);

	if (b - a < 11){

		resp = 1;
		for (i = b; i > a; i--){

			resp *= (i % 10);
			resp %= 10;

		}

		printf("%llu\n", resp);

	}
	else printf("0\n");

	return 0;
}
