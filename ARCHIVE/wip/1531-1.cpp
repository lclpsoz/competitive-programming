//Calculating Pisano Period
#include <bits/stdc++.h>
using namespace std;

int main (){

	int arr[3];
	int mod;
	long long max = 2e11;

	for (mod = 9.99e5; mod <= 1e6; mod++){
	arr[0] = arr[1] = 1;
	for (int i = 2; i < max; i++){

		arr[i%3] = (arr[(i-1)%3] + arr[(i-2)%3])%mod;

		if (arr[i%3] == 0 && arr[(i-1)%3] == 1){

			printf("%d: %d\n", mod, i+1);
			break;

		}

	}
	}

	return 0;
}
