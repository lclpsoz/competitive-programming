#include <bits/stdc++.h>
using namespace std;

int mdc (int a, int b){

	if (a == 0) return b;
	return mdc(b%a, a);

}

int mmc (int a, int b){

	return (a * b) / mdc(a, b);

}

int main (){

	int years;
	int a, b, c, aux;

	while (scanf("%d", &years) != EOF){

		scanf("%d %d %d", &a, &b, &c);

		aux = mmc(a, b);
		printf("%d\n", mmc(aux, c)-years);

	}

	return 0;
}
