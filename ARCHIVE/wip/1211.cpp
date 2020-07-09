#include <bits/stdc++.h>
using namespace std;

const int MAXS = 250;

int i, j;
int qnt, size, econ;
char str[MAXS], model[MAXS];
bool test;

int main (){

	while(scanf("%d", &qnt) != EOF){

		econ = 0;
		scanf("%s", str);
		strcpy(model, str);
		size = strlen(model);
		for (i = 1; i < qnt; i++){

			scanf("%s", str);
			for (j = 0, test = true; j < size; j++){

				if (test && str[j] == model[j]){

					str[j] = ' ';
					econ++;

				}
				else{

					model[j] = str[j];
					test = false;

				}
			}
			puts(str);
		}
		printf("%d\n", econ);

	}

	return 0;
}
