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

int a[N], d[N];
multiset<int> st;

int main () {
	int n, m, k;
	scanf ("%d %d %d", &n, &m, &k);
	int ans = 0;
	for (int i = 0; i < n; i++)
		scanf ("%d", &a[i]);
	ans = a[n-1] - a[0] + 1;
	for (int i = 0; i < n-1; i++)
		st.insert (- (a[i+1] - a[i]) + 1);
	--k;
	while (k--) {
		ans += *st.begin();
		st.erase (st.begin());
	}
	printf ("%d\n", ans);
	
	return 0;
}
