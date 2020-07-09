#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long double SQ_T = sqrt(3);
const int MAXN = 1e3+10;

int i, j;
int l;
long double val1, val2, tria, lad;
long double arr[MAXN];
ll multi;

int main(){

	val2 = 1;
	val1 = 0;
	for (i = 0, tria = 1, lad = 1; i < 100 && val2 != val1; i++){

		val2 = val1;
		val1 += tria * (((lad * lad) * SQ_T) / 4);
		lad /= 3;
		i == 0 ? tria = 3: tria *= 4;

	}

	for (i = 1; i <= 1000; i++)
		arr[i] = val1 * i * i;

	while (scanf("%d", &l) != EOF)
		printf("%0.2Lf\n", arr[l]);

	return 0;
}
