#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;

int main (){

	scanf("%d %d %d %d", &a, &b, &c, &d);

	if (a*b == c*d) printf("0\n");
	else if (a*b > c*d) printf("-1\n");
	else printf("1\n");

	return 0;
}
