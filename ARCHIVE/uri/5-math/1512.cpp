#include <bits/stdc++.h>
using namespace std;

int mdc (int a, int b){

	if (b == 0) return a;
	return mdc(b, a%b);

}

int mmc (int a, int b){

	return (a*b) / mdc(a, b);

}

int main (){

	int n, a, b, resp;

	scanf("%d %d %d", &n, &a, &b);
	while (n){

		//printf("MMC(%d,%d) = %d\n", a, b, mmc(a, b));
		resp = (n/a) + (n/b) - (n/mmc(a, b));
		printf("%d\n", resp);

		scanf("%d %d %d", &n, &a, &b);

	}

	return 0;
}
