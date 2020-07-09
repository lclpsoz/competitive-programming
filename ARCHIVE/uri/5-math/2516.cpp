#include <bits/stdc++.h>
using namespace std;

double d, a, b;

int main (){

	while(scanf("%lf %lf %lf", &d, &a, &b) != EOF)
		if (b > a) printf("impossivel\n");
		else printf("%.2lf\n", d / (a - b));

	return 0;
}
