#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long double SQ_T = sqrt(3);
const int MAXN = 1e3+10;

int i, j;
int l;
long double val1, val2, tria, lad;
double arr[MAXN];
ll multi;

int main(){

	for (j = 1; j <= 1000; j++){
		val2 = 1;
		val1 = 0;
		for (i = 0, tria = 1, lad = j; i < 100 && (floor(val2*100) != floor(val1*100)); i++){

			val2 = val1;
			val1 += tria * (((lad * lad) * SQ_T) / 4);
			lad /= 3;
			i == 0 ? tria = 3: tria *= 4;

		}
		arr[j] = val1;

	}

	while (scanf("%d", &l) != EOF)
		printf("%0.2f\n", arr[l]);

	return 0;
}
