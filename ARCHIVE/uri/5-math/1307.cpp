#include <bits/stdc++.h>
using namespace std;

const int MAXS = 1e3;

int i, j, k;
int qnt;
char str[MAXS];
long long val1, val2;

int mdc (long long a, long long b){

	if (b == 0) return a;
	return mdc(b, a%b);

}

int main (){

	scanf("%d", &qnt);

	for (i = 0; i < qnt; i++){

		val1 = val2 = 0;
		scanf("%s", str);
		for (j = strlen(str)-1, k = 0; j >= 0; j--, k++)
			val1 += pow(2, k) * (str[j] - '0');

		scanf("%s", str);
		for (j = strlen(str)-1, k = 0; j >= 0; j--, k++)
			val2 += pow(2, k) * (str[j] - '0');

		//printf("%lld %lld\n", val1, val2);
		//printf("%d\n", mdc(val1, val2));
		if (mdc(val1, val2) > 1) printf("Pair #%d: All you need is love!\n", i+1);
		else printf("Pair #%d: Love is not all you need!\n", i+1);


	}

	return 0;
}
