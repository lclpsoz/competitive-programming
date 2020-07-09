#include <bits/stdc++.h>
using namespace std;

const int MAXN = 51;

int i;
int qnt, val;
int arr[MAXN];

int main (){

	for (i = 1; i < MAXN; i++)
		arr[i] = (((i+1)*(i+1))/2) - 1;

	scanf("%d", &qnt);
	for (i = 0; i < qnt; i++){

		scanf("%d", &val);
		printf("%d\n", arr[val]);

	}

	return 0;
}
