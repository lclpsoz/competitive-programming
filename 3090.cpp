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
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

int n, m, s;
// int mat[10100][10100];

int main () {
	scanf("%d %d %d", &n, &m, &s);
	int total = 0, val = 0;
	while(s--) {
		int x, y, h;
		scanf("%d %d %d", &x, &y, &h);
		double ax = n * (double)y/m;
		double ay = m * (double)x/n;
		// printf("%d %d ax = %lf\n", x, y, ax, ay);
		// mat[y][x] = h;
		total += h;
		if(x <= ax)
			val += h;
	}
	printf("%d %d\n", val, total-val);
	// for(int i = 0; i <= m; i++)
	// 	for(int j = 0; j <= n; j++) {
	// 		printf("%d%c", mat[i][j], " \n"[j==n]);

	return 0;
}
