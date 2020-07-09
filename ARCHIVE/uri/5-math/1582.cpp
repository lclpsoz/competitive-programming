#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int aux;

void order (){

	if (a < b){

		aux = a;
		a = b;
		b = aux;

	}
	if (a < c){

		aux = a;
		a = c;
		c = aux;

	}
}

int mdc (int x, int y){

	if (y == 0) return x;
	return mdc(y, x%y);

}

int main (){

	while (scanf("%d %d %d", &a, &b, &c) != EOF){

		order();

		printf("tripla");

		if ((a*a) == ((b*b) + (c*c))){

			printf(" pitagorica");
			if (mdc(a, b) == 1)
				printf(" primitiva");

		}

		printf("\n");

	}

	return 0;
}
