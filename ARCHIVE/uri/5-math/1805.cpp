#include <bits/stdc++.h>

long long unsigned a, b;

int main (){

	scanf("%llu %llu", &a, &b);

	a--;
	printf("%llu\n", ((b*(b+1))/2) - ((a*(a+1))/2));

	return 0;
}
