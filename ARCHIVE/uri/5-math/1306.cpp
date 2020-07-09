#include <bits/stdc++.h>
using namespace std;

int i;
double suf, roads, qnt;

int main (){

	scanf("%lf %lf", &roads, &qnt);
	while (roads && qnt){

		suf = ceil(roads/qnt) - 1;

		if (suf > 26)
			printf("Case %d: impossible\n", ++i);
		else
			printf("Case %d: %.0lf\n", ++i, suf);

		scanf("%lf %lf", &roads, &qnt);

	}

	return 0;
}
