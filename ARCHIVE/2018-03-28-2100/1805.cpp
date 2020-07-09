#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned llu;

llu a, b;


int main (){

	scanf("%llu %llu", &a, &b);

	printf("%llu\n", ((a+b) * (b - a + 1)) / (llu) 2);

	return 0;
}
