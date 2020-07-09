#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+10;

int i;
int mod, qnt;
int arr[MAXN];

bool ord (const int &a, const int &b){

	const int a_m = a % mod, b_m = b % mod;

	if (a_m < b_m)
		return true;
	else if (a_m == b_m){

		if (abs(a%2) > abs(b%2))
			return true;
		else if (abs(a%2) == abs(b%2)){

			if (abs(a%2) == 1)
				return a > b;
			else if (abs(a%2) == 0)
				return a < b;

		}
	}

	return false;

}

int main (){

	do{

		scanf("%d %d", &qnt, &mod);

		printf("%d %d\n", qnt, mod);
		for (i = 0; i < qnt; i++)
			scanf("%d", &arr[i]);

		sort(arr, arr+qnt, ord);

		for (i = 0; i < qnt; i++)
			printf("%d\n", arr[i]);

	} while (qnt || mod);

	return 0;
}
