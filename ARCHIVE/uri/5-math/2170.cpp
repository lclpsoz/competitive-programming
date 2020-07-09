#include <bits/stdc++.h>
using namespace std;

int i;
long double a, b;

int main (){

	while (scanf("%Lf %Lf", &a, &b) != EOF){

		printf("Projeto %d:\n", ++i);
		printf("Percentual dos juros da aplicacao: %.2Lf %%\n\n", (((b/a)-1) * 100.0));

	}

	return 0;
}
