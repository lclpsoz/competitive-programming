#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+10;

int i;
int qnt, arr[MAXN], sum;

int main (){

	while (scanf("%d", &qnt) != EOF){

		for (i = 0; i < qnt; i++)
			scanf("%d", &arr[i]);

		sort(arr, arr + qnt);

		sum = 0;
		for (i = 0; i < (qnt/2); i++)
			sum += arr[qnt-i-1] - arr[i];

		printf("%d\n", sum);

	}

	return 0;
}
