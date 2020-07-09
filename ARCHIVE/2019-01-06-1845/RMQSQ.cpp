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
 
 
const int N = 1e5+100, K = 22;
 
int n;
int sparse[N][K];
 
void buildSparse () {
	int bef = 1;
	for (int i = 1; 1<<i <= n; i++) {
		for (int j = 0; j <= n-(1<<i); j++)
			sparse[j][i] = min (sparse[j][i-1], sparse[j+bef][i-1]);
		bef <<= 1;
	}
}
 
int query (int l, int r) {
	int qnt = (r-l+1);
	int k = (31-__builtin_clz (qnt));
	int b = 1<<k;
	return min (sparse[l][k], sparse[l+(qnt-b)][k]);
}
 
int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf ("%d", &sparse[i][0]);
	buildSparse();
	
	int q; scanf ("%d", &q);
	while (q--) {
		int l, r;
		scanf ("%d %d", &l, &r);
		printf ("%d\n", query (l, r));
	}
	
	return 0;
}