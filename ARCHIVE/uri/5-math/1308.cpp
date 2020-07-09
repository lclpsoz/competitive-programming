#include <bits/stdc++.h>
using namespace std;

int i;
int qnt;
double n, x;

int main (){

	scanf("%d", &qnt);

	for (i = 0; i < qnt; i++){

		scanf("%lf", &x);

		n = floor((sqrt(1 + 8*x) - 1)/2);
		printf("%.0lf\n", n);

	}

	return 0;
}
