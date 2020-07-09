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

int n, k, a, b;
vector<int> heroes;

int amnt (int l, int r) {
	return upper_bound (heroes.begin(), heroes.end(), r) - 
			lower_bound (heroes.begin(), heroes.end(), l);
}

ll solve (int l, int r) {
	int q = amnt (l, r);
	// printf ("%d %d %d\n", l, r, q);
	if (q == 0)
		return a;
	if (r - l == 0)
		return (ll)b*q*(r-l+1);
	int le = (r-l+1);
	return min ((ll)b*q*le, solve (l, l + le/2 - 1) + solve (l + le/2, r));
}

int main () {
	scanf ("%d %d %d %d", &n, &k, &a, &b);
	for (int i = 0; i < k; i++) {
		int x;
		scanf ("%d", &x);
		heroes.push_back (x);
	}
	sort (heroes.begin(), heroes.end());
	printf ("%lld\n", solve (1, 1<<n));

	return 0;
}
