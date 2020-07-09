#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+10;

int i, j;
int qnt;
int arr[MAXN], mini[MAXN], numb, val;

int main(){

	for (i = 1; i <= 1000; i++){

		val = 0;
		for (j = 1; j <= i; j++)
			if (i%j == 0) val++;

		if (val % 2 == 0)
			mini[i] = mini[i-1] + 1;
		else
			mini[i] = mini[i-1];

	}

	scanf("%d", &qnt);

	for (i = 0; i < qnt; i++){

		scanf("%d", &numb);
		printf("%d\n", mini[numb]);

	}



	return 0;
}
