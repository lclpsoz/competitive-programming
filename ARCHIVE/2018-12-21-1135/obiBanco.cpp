#include "bits/stdc++.h"
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 5010;

int acu[N];
int vals[] = {2, 5, 10, 20, 50, 100};

int main () {
	acu[0] = 1;
	int n;
	scanf ("%d", &n);
	for (int i = 0; i < 6; i++) {
		int qnt;
		scanf ("%d", &qnt);
		for (int k = n-vals[i]; k >= 0; k--)
			for (int j = 1; j <= qnt and k+j*vals[i] <= n; j++)
				acu[k+(j*vals[i])] += acu[k];
	}
	
	
	printf ("%d\n", acu[n]);
	
	return 0;
}
