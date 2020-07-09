#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4;

int i, j;
int n;
int arr[MAXN];

int main (){

	for (i = 0; i <= 5e3; i++)
		arr[i] = i*i;
	arr[i] = 3e7;

	scanf("%d", &n);
	while (n){

		printf("1");
		for (i = 2; arr[i] <= n; i++)
			printf(" %d", arr[i]);
		printf("\n");

		scanf("%d", &n);
	}

	return 0;
}
