#include <bits/stdc++.h>
using namespace std;

const int MAXS = 60;

int i;
int qnt, maxi;
char str[MAXS][MAXS];

int main (){

	bool test = false;
	while(scanf("%d", &qnt), qnt){

		if (test) printf("\n");

		maxi = 0;
		for (i = 0; i < qnt; i++){

			scanf("%s", str[i]);
			maxi = max(maxi, (int)strlen(str[i]));

		}

		for (i = 0; i < qnt; i++)
			printf("%*s\n", maxi, str[i]);

		test = true;


	}

	return 0;
}
