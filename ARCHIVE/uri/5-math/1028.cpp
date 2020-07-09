#include <bits/stdc++.h>
using namespace std;

int mdc (int a, int b){

	if (b == 0) return a;
	return mdc(b, a%b);

}

int i;
int qnt;

int main (){

	int a, b;

	scanf("%d", &qnt);

	for (i = 0; i < qnt; i++){

		scanf("%d %d", &a, &b);
		printf("%d\n", mdc(a, b));

	}

	return 0;
}
