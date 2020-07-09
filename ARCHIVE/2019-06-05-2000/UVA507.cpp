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

int t, n;
ll pref[20100];

int main () {
	scanf ("%d", &t);
	for (int r = 1; r <= t; r++) {
		scanf ("%d", &n);
		--n;
		for (int i = 1; i <= n; i++) {
			scanf ("%lld", &pref[i]);
			pref[i] += pref[i-1];
		}
		
		ll mini = 0;
		int posMini = 0;
		ll maxi = 0;
		pii ans;
		for (int i = 1; i <= n; i++) {
			if (pref[i] - mini > maxi or (pref[i] - mini == maxi and (i-posMini) > ans.y-ans.x)) {
				maxi = pref[i] - mini;
				ans = {posMini+1, i+1};
			}
			if (pref[i] < mini) {
				mini = pref[i];
				posMini = i;
			}
		}
		if (maxi == 0)
			printf ("Route %d has no nice parts\n", r);
		else
			printf ("The nicest part of route %d is between stops %d and %d\n", r, ans.x, ans.y);
	}

	return 0;
}
