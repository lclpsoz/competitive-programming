#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int main (){

	while (scanf("%d %d %d", &a, &b, &c), a || b || c)
		printf("%d\n", (int) pow(a*b*c, 0.33333333333333));

	return 0;
}
