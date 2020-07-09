#include <bits/stdc++.h>
using namespace std;

int i;
int qnt;
long long unsigned numb;

int main(){

	scanf("%d", &qnt);
	for (i = 0; i < qnt; i++){

		scanf("%llu", &numb);
		printf("%llu\n", 1 + (numb * (numb+1))/2);

	}

	return 0;
}
