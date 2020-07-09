#include <bits/stdc++.h>
using namespace std;

#define MAXN (int) 1e3+10

int i;
int qnt, arr[MAXN], acc, last;

int main (){

	scanf("%d %d", &qnt, &acc);

	for (i = 0; i < qnt; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr+qnt);

	i = qnt - acc;
	last = arr[i--];
	while (arr[i--] == last)
		acc++;

	printf("%d\n", acc);

	return 0;
}
