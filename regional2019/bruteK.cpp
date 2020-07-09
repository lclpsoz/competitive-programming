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

int n;
bool mp[1010][2];

int dfs (int x, int y, int prof) {
	if (y < 0 or y > 1) return 0;
	if (x < 1 or x > n) return 0;
	if (mp[x][y]) return 0;
	if (prof == 2*n) {
		if (x == n)
			printf ("\n(%d %d)", x, y);
		return 1;
	}
	mp[x][y] = true;
	int ret = 0;
	// putchar ('\n');
	// for (int i = 0; i < prof; i++)
	// 	printf ("  ");
	// printf ("%d %d", x, y);
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			ret += dfs (x+i, y+j, prof+1);
	mp[x][y] = false;
	return ret;
}

int main () {
	for (n = 1; n <= 5; n++) {
		printf ("n = %d", n);
		int total = 0;
		for (int i = 1; i <= n/2; i++) {
			int now = dfs (i, 0, 1);
			printf (", %d %d", now, 4*now);
			total += 4*now;
		}
		if (n&1) {
			int now = dfs ((n+1)/2, 0, 1);
			total += 2*now;
			printf (", %d %d | ", now, 2*now);
		} else
			printf (" | ");
		printf ("total = %d\n", total);
		total = 0;
	}


	return 0;
}
