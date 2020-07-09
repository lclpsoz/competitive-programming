#include <bits/stdc++.h>
using namespace std;

const double TAN_36 = tan(((36 * M_PI) / 180));

int i;
int qnt;
double n;

int main (){

	scanf("%d", &qnt);
	for (i = 0; i < qnt; i++){

		scanf("%lf", &n);
		printf("%.3lf\n", (5 * n * n) / (4 * TAN_36));

	}

	return 0;
}
