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

const int N = 3e5 + 10;

int n;
int pref[N];
map<int, int> mp[2];

int main () {
	scanf ("%d", &n);
	pref[0] = 0;
	mp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf ("%d", &x);
		pref[i] = pref[i-1]^x;
		mp[i%2][pref[i]]++;
	}
	ll ans = 0;
	for (auto pp : mp[0])
		ans += (pp.y*1LL*(pp.y-1))/2;
	for (auto pp : mp[1])
		ans += (pp.y*1LL*(pp.y-1))/2;
	printf ("%lld\n", ans);

	return 0;
}
