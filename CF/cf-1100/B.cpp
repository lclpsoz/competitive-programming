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

const int N = 1e5+10;

int n, m;
int qnt[N];
bool ans[N];

int main () {
	scanf ("%d %d", &n, &m);
	int ax = n;
	for (int i = 0; i < m; i++) {
		int x;
		scanf ("%d", &x);
		qnt[x]++;
		if (qnt[x] == 1)
			--ax;
		if (ax == 0) {
			ax = n;
			for (int j = 1; j <= n; j++) {
				--qnt[j];
				if (qnt[j] > 0)
					--ax;
			}
			ans[i] = true;
		}
	}
	for (int i = 0; i < m; i++)
		putchar (ans[i] ? '1' : '0');
	putchar ('\n');

	return 0;
}
