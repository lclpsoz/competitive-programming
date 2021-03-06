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

int n, k, m;
ll oriTotal;
vector<int> vec;

int main () {
	scanf ("%d %d %d", &n, &k, &m);
	for (int i = 0; i < n; i++) {
		int x; 
		scanf ("%d", &x);
		oriTotal += x;
		vec.push_back (x);
	}
	sort (vec.begin(), vec.end(), greater<int>());

	ld ans = ((ld)oriTotal + min (k*1LL*len (vec), (ll)m))/len(vec);
	for (int i = 1; i <= n-1 and m; i++) {
		oriTotal -= vec.back();
		vec.pop_back ();
		--m;
		ans = max (ans, ((ld)oriTotal + min (k*1LL*len (vec), (ll)m))/len(vec));
	}
	printf ("%.10Lf\n", ans);

	return 0;
}
