#include <bits/stdc++.h>
using namespace std;

int mdc (int a, int b){

	if (a == 0) return b;
	return mdc (b%a, a);

}

int main (){

	int blues, blacks, teams, d;

	while (scanf("%d %d %d", &blues, &blacks, &teams) != EOF){

		d = mdc(blues, blacks);
		//printf("%d\n", d);

		if (((blues / d) + (blacks / d)) >= teams) printf("sim\n");
		else printf("nao\n");

	}

	return 0;
}
