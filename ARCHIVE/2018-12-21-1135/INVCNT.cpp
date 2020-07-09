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

const int N = 200010;

int t;
int n;
int bit[N], a[N];

void add (int p, int v) {
	for (int i = p; i < N; i+=i&-i)
		bit[i] += v;
}

ll sum (int p) {
	ll r = 0;
	for (int i = p; i >= 1; i-=i&-i)
		r += bit[i];
	return r;
}

int main () {
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d", &n);
		vector<int> vec;
		for (int i = 0; i < n; i++) {
			scanf ("%d", &a[i]);
			vec.push_back (a[i]);
		}
		sort (vec.begin(), vec.end());
		ll ans = 0;
		for (int i = n-1; i >= 0; i--) {
			a[i] = lower_bound (vec.begin(), vec.end(), a[i])-vec.begin()+1;
			ans += sum (a[i]);
			add (a[i], 1);
		}
		memset (bit, 0, sizeof bit);
		printf ("%lld\n", ans);
	}

	return 0;
}
