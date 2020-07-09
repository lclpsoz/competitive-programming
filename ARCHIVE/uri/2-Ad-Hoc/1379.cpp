#include <bits/stdc++.h>
using namespace std;

int main (){

	long long int a, b;
	scanf("%lld %lld", &a, &b);
	while (a || b){

		printf("%lld\n", 2*a - b);

		scanf("%lld %lld", &a, &b);

	}

	return 0;
}
