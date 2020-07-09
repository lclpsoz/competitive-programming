#include <bits/stdc++.h>
using namespace std;

const int MAXS = 125;

int i, j, k;
int qnt_a, qnt_b;
int ans;
char str[MAXS];


int main (){

	scanf("%d", &qnt_a);
	for (i = 0; i < qnt_a; i++){

		ans = 0;
		scanf("%d", &qnt_b);
		for (j = 0; j < qnt_b; j++){

			scanf("%s", str);
			for (k = 0; k < strlen(str); k++){

				ans += (str[k]-'A') + j + k;

			}


		}

		printf("%d\n", ans);
	}

	return 0;
}
