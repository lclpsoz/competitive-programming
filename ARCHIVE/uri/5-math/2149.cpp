#include <bits/stdc++.h>
using namespace std;

int i;
int pos;
long long unsigned arr[20];

int main (){

	arr[1] = 0;
	arr[2] = 1;
	for (i = 3; i < 18; i++)
		if (i % 2)
			arr[i] = arr[i-1] + arr[i-2];
		else
			arr[i] = arr[i-1] * arr[i-2];

	while (scanf("%d", &pos) != EOF)
		printf("%llu\n", arr[pos]);

	return 0;
}

