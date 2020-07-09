#include <bits/stdc++.h>
using namespace std;

int i, j;
int qnt;
unsigned int numb;

int main(){


	scanf("%d", &qnt);

	for (i = 0; i < qnt; i++){

		scanf("%u", &numb);
		printf("%u\n", (unsigned int) (numb - (int)sqrt(numb)));

	}



	return 0;
}
