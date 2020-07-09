#include <bits/stdc++.h>
using namespace std;

int i, j;
int qnt;
int val, k;
char str[50];
long long unsigned resp;

int main (){

	scanf("%d", &qnt);
	for (i = 0; i < qnt; i++){

		resp = 1;
		scanf("%d%s", &val, str);

		k = strlen(str);

		for (j = val; j > 0; j -= k)
			resp *= j;

		printf("%llu\n", resp);

	}

	return 0;
}
