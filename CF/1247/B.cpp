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

const int N = 1e6 + 10;

int t, n, k, d;
int q[N], a[N];
set<int> st;

int main () {
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d %d %d", &n, &k, &d);
		for (int i = 0; i < n; i++) {
			scanf ("%d", &a[i]);
		}
		int r = d;
		int ans = k;
		int now = 0;
		for (int i = 0; i < r; i++) {
			q[a[i]]++;
			if (q[a[i]] == 1) {
				++now;
				st.insert (a[i]);
			}
		}
		ans = now;
		while (r < n) {
			q[a[r-d]]--;
			if (q[a[r-d]] == 0) {
				--now;
				st.erase (a[r-d]);
			}
			q[a[r]]++;
			if (q[a[r]] == 1) {
				++now;
				st.insert (a[r]);
			}
			++r;
			ans = min (ans, now);
		}
		for (int v : st) q[v] = 0;
		st.clear();
		printf ("%d\n", ans);
	}

	return 0;
}
