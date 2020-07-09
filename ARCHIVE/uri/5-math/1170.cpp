#include <bits/stdc++.h>
using namespace std;

int i;
int qnt;
double val;

int main (){

	scanf("%d", &qnt);

	for (i = 0; i < qnt; i++){

		scanf("%lf", &val);

		printf("%d dias\n", (int) ceil(log2(val)));

	}

	return 0;
}
