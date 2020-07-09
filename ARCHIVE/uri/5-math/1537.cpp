//In this question the logic is to divide the factorial of the input n and divide it by 3!, so the array with all possible value starts with 1 and then *4, then *5, without *2, *3.
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9+9, MAXN = 1e5+50;

int i;
int n;
int rests[MAXN];

int main (){

	rests[3] = 1;
	for (i = 4; i < MAXN; i++)
		rests[i] = ((ll)rests[i-1] * (ll)i) % MOD;

	scanf("%d", &n);
	while (n){

		printf("%d\n", rests[n]);

		scanf("%d", &n);

	}

	return 0;
}
