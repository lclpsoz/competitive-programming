#include <bits/stdc++.h>
using namespace std;

int i;
int qnt;
double h = 5.0, amnt, a, b;

int main (){

	while (scanf("%d", &qnt), qnt){
		for (i = 0; i < qnt; i++){

			scanf("%lf %lf %lf", &amnt, &a, &b);
			printf("Size #%d:\n", i+1);
			printf("Ice Cream Used: %0.2lf cm2\n", amnt*(h*(a+b))/2);

		}
		printf("\n");
	}

	return 0;
}
