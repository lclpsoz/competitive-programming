#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;

int i;
int qnt;
int arr[MAXN];

int main(){


	while (scanf("%d", &qnt) != EOF){

		for (i = 0; i < qnt; i++)
			scanf("%d", &arr[i]);

		sort(arr, arr+i);

		for (i = 0; i < qnt; i++)
			printf("%04d\n", arr[i]);

	}

	return 0;
}
