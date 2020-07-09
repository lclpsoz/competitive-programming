//To get the the last digit != 0 from a number that will be a product of it self -1 x times (variable 'qnt') will use mod 1e8, to not result in zero if input is 2e7 (maximum possible)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e8;

int i;
int n, qnt;
ll value, aux;

int main (){

	while (scanf("%d %d", &n, &qnt) != EOF){

		if (!qnt){

			printf("1\n");

		}
		else{

			value = 1;
			for (i = 0; i < qnt; i++){

				aux = n-i;
				while (!(aux % 10)) aux /= 10;

				value = value * aux;
				while (!(value % 10)) value /= 10;
				value %= MOD;

				//printf("    %d\t%lld\n", i, value);

			}

			printf("%lld\n", value % 10);

		}
	}

	return 0;
}
