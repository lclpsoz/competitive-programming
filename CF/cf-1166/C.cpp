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
vector<int> vec, ax;

int main () {
	scanf ("%d", &n);
	while (n--) {
		int x;
		scanf ("%d", &x);
		vec.push_back (abs(x));
		ax.push_back (x);
	}
	sort (vec.begin(), vec.end());
	ll ans = 0;
	for (int i = 0; i < len (vec)-1; i++) {
		auto it = upper_bound (vec.begin(), vec.end(), 2*vec[i]);
		// printf ("  dist = %d\n", (int)(it-vec.begin()));
		int d = it-vec.begin()-i-1;
		ans += d;
		// printf("  i = %d, d = %d, ans = %d\n", i, d, ans);
	}
	ll brute = 0;
	for (int i = 0; i < len (ax); i++)
		for (int j = i+1; j < len (ax); j++) {
			int x = ax[i], y = ax[j];
			if (abs (x) > abs(y)) swap (x, y);
			int a = abs (x - y), b = abs (x + y);
			if (a > b) swap (a, b);
			brute += (a <= abs (x) and abs(y) <= b);
			// printf (" brute: %d %d %d\n", x, y, brute);
		}
	assert (brute==ans);
	printf ("%lld\n", ans);

	return 0;
}
