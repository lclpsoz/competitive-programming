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

const ll INF = 1e18 + 1e17;
const int N = 1e5 + 100;

int n;
vector<ll> vec;
ll pref[N];
vector<ll> dif;

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		ll x;
		scanf ("%lld", &x);
		vec.push_back (x);
	}

	sort (vec.begin(), vec.end());
	vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
	for (int i = 1; i < len(vec); i++)
		dif.push_back (vec[i]-vec[i-1]);
	dif.push_back (INF);
	sort (dif.begin(), dif.end());
	pref[0] = dif[0];
	for (int i = 1; i < len (dif)-1; i++)
		pref[i] = pref[i-1] + dif[i];
	
	int q;
	scanf ("%d", &q);
	while (q--) {
		ll l, r;
		scanf ("%lld %lld", &l, &r);
		ll sz = r-l+1;
		auto it = lower_bound (dif.begin(), dif.end(), sz);
		int pos = (int)(it - dif.begin());
		if (pos) {
			printf ("%lld ", pref[pos-1] + (len(dif)-pos)*1ll*sz);
		} else
			printf ("%lld ", len(dif)*1ll*sz);
	}
	putchar ('\n');

	return 0;
}
