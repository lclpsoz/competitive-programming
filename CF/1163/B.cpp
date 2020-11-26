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
int pos[100010];
int qnt[100010];

int main () {
	int ans = 1;
	scanf ("%d", &n);
	pos[0] = n;
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf ("%d", &x);
		pos[qnt[x]]--;
		qnt[x]++;
		mx = max (mx, qnt[x]);
		pos[qnt[x]]++;
		if (pos[0]+pos[1] == n) {
			ans = i;
			continue;
		}
		
		if (pos[mx] == 1 and pos[mx-1]+pos[mx]+pos[0] == n) {
			ans = i;
			continue;
		}

		if (pos[1] == 1 and pos[mx]+pos[1]+pos[0] == n) {
			ans = i;
			continue;
		}
	}
	printf ("%d\n", ans);

	return 0;
}
