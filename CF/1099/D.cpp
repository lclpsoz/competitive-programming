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

const ll INF = 1e18l;
const int N = 1e5+10;

int n;
int parent[N];
vector<int> child[N];
ll s[N], a[N];

void imp () {
	printf ("-1\n");
	exit (0);
}

void solve (int p) {
	for (int v : child[p]) {
		ll val = INF;
		if (s[v] == -1) {
			for (int ch : child[v])
				val = min (val, s[ch] - s[p]);
// 			printf("out of here (%d)\n", v);
			if (val < 0)
				imp();
			if (val == INF)
				val = 0;
// 			printf ("%d %lld\n", v, val);
			a[v] = val;
			s[v] = s[p] + val;
		} else
			a[v] = s[v] - s[p];
		solve (v);
	}
}

int main () {
	scanf ("%d", &n);
	for (int i = 2; i <= n; i++) {
		int p;
		scanf ("%d", &p);
		parent[i] = p;
		child[p].push_back (i);
	}
	for (int i = 1; i <= n; i++)
		scanf ("%lld", &s[i]);
	a[1] = s[1];
	solve (1);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
// 		printf ("%d: %lld\n", i, a[i]);
		ans += a[i];
	}
	printf ("%lld\n", ans);

	return 0;
}
