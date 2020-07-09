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

const int N = 1e5 + 10;

int n, m;
int b[N], g[N];
vector<int> vec, vecG;

int main () {
	scanf ("%d %d", &n, &m);
	int mnG = 1e9;
	for (int i = 0; i < n; i++) {scanf ("%d", &b[i]); vec.push_back (b[i]);}
	sort (vec.begin(), vec.end());
	int mxB = vec.back();
	int mx2B = vec[len(vec)-2];
	for (int i = 0; i < m; i++) {
		scanf ("%d", &g[i]);
		mnG = min (mnG, g[i]);
		if (g[i] > mxB)
			vecG.push_back (g[i]);
	}
	ll ans = 0;
	sort (vecG.begin(), vecG.end());
	if (mxB > mnG) {
		printf ("-1\n");
		exit (0);
	} else {
		for (int i = 0; i < n; i++)
			ans += b[i]*1LL*m;
		if (len (vecG) == m) {
			for (int i = 1; i < m; i++)
				ans += vecG[i]-mxB;
			ans += vecG.front()-mx2B;
		} else {
			for (int x : vecG)
				ans += x-mxB;
		}
		printf ("%lld\n", ans);
	}


	return 0;
}
