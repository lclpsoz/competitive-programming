#include <bits/stdc++.h>
using namespace std;

const int MAXN = 40;

int i;
int qnt, n;
int fib[MAXN];

int main (){

	fib[0] = 0;
	fib[1] = 1;
	for (i = 2; i < MAXN; i++)
		fib[i] = fib[i-1] + fib[i-2];

	scanf("%d", &qnt);
	for (i = 0; i < qnt; i++){

		scanf("%d", &n);
		printf("fib(%d) = %d calls = %d\n", n, 2*fib[n+1] - 2, fib[n]);


	}

	return 0;
}
