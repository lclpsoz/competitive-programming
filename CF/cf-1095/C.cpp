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

int n, k;
vector<int> base;
vector<int> ans;

void solve (int x) {
	if (k and x > 1) {
		k--;
		solve (x/2);
		solve (x/2);
	} else
		ans.push_back (x);
}

int main () {
	scanf ("%d %d", &n, &k);
	if (k > n or __builtin_popcount (n) > k)
		printf ("NO\n");
	else {
		printf ("YES\n");
		for (int i = 0; i < 32; i++)
			if ((1<<i) & n)
				base.push_back (1<<i);
		k -= len (base);
		for (int i = 0; i < len (base); i++) {
			solve (base[i]);
		}
		for (int i = 0; i < len (ans); i++) {
			if (i) putchar (' ');
			printf ("%d", ans[i]);
		}
		putchar ('\n');
	}

	return 0;
}
