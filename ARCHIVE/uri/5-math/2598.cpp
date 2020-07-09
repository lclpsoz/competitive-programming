#include <bits/stdc++.h>
using namespace std;

int i;
int qnt;
double av, radar;

int main (){

	scanf("%d", &qnt);

	for (i = 0; i < qnt; i++){

		scanf("%lf %lf", &av, &radar);
		printf("%.0lf\n", ceil(av/radar));

	}

	return 0;
}
