#include <bits/stdc++.h>
using namespace std;

int i;
int qnt;
long long int raf, bet, car;
int x, y;

int main (){

	scanf("%d", &qnt);

	for (i = 0; i < qnt; i++){

		scanf("%d %d", &x, &y);

		raf = (9 * x * x) + (y * y);
		bet = (2 * x * x) + (25 * y * y);
		car = (-100 * x) + (y * y * y);

		if (raf > bet && raf > car)
			printf("Rafael ganhou\n");
		else if (bet > raf && bet > car)
			printf("Beto ganhou\n");
		else
			printf("Carlos ganhou\n");

	}

	return 0;
}
