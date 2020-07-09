#include <bits/stdc++.h>
using namespace std;

int i, j;
int qnt;
unsigned int n;
bool prime;

int main (){

	scanf("%d", &qnt);

	for (i = 0; i < qnt; i++){

		scanf("%u", &n);

		prime = true;
		for (j = 2; j*j <= n && prime; j++)
			if (!(n % j)) prime = false;

		if (prime) printf("Prime\n");
		else printf("Not Prime\n");

	}

	return 0;
}
