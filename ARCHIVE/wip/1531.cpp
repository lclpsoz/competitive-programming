#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned llu;

int main (){

	int i;
	int arr[3], n;
	int mod, mod_p;

	while (scanf("%d %d", &n, &mod) != EOF){

		//Pisano Period
		i = 2;
		arr[0] = arr[1] = 1;
		while (arr[(i-1)%3] != 0 || arr[(i-2)%3] != 1){

			arr[i%3] = (arr[(i-1)%3] + arr[(i-2)%3])%mod;
			//printf("%d\n", arr[i%3]);
			i++;

		}

		mod_p = i;
		printf("%d\n", mod_p);

		//Fast doubling for Fibonacci



	}

	return 0;
}
