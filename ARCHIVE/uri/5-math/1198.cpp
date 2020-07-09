#include <bits/stdc++.h>
using namespace std;

long long unsigned int a, b;

int main (){

	while (scanf("%llu %llu", &a, &b) != EOF){

		if (a > b)
			printf("%llu\n", a - b);
		else
			printf("%llu\n", b - a);

	}

	return 0;
}
