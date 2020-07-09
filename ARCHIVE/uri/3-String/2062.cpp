#include <bits/stdc++.h>
using namespace std;

const int MAXS = 100;

int i;
int qnt;
char str[MAXS];

int main(){

	scanf("%d", &qnt);

	for (i = 0; i < qnt; i++){

		scanf("%s", str);
		if (strlen(str) == 3 && ((str[0] == 'O' && str[1] == 'B') || (str[0] == 'U' && str[1] == 'R'))){

			str[2] = 'I';
			printf("%s", str);

		}
		else
			printf("%s", str);

		if (i < qnt-1) printf(" ");
	}
	printf("\n");

	return 0;
}
