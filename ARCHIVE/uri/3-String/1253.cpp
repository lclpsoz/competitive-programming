#include <bits/stdc++.h>
using namespace std;

const int MAXS = 60;

int i, j;
int qnt, n;
char str[MAXS], c;

int main (){

	scanf("%d", &qnt);
	for (i = 0; i < qnt; i++){

		scanf("%s %d", str, &n);

		for (j = 0; j < strlen(str); j++){

			str[j] -= n;
			if ((str[j] - 'A') < 0) str[j] += -'A' + 'Z' + 1;

		}
		printf("%s\n", str);

	}

	return 0;
}
