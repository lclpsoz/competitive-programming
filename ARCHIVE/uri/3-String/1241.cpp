#include <bits/stdc++.h>
using namespace std;

const int MAXS = 1e3+10;

int i, j, k;
int qnt;
char str1[MAXS], str2[MAXS];
bool test;

int main (){

	scanf("%d", &qnt);
	for (i = 0; i < qnt; i++){

		scanf("%s %s", str1, str2);
		if (strlen(str1) >= strlen(str2)){

			test = true;
			for (j = strlen(str1)-1, k = strlen(str2)-1; j >= 0 && k >= 0; j--, k--){

				if (str1[j] != str2[k]){

					test = false;
					break;

				}
			}
		}
		else
			test = false;

		if (test) printf("encaixa\n");
		else printf("nao encaixa\n");


	}

	return 0;
}
