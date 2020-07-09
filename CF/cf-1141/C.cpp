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

const int N = 2e5+10;

int n;
int q[N];
ll a[N];
map<ll, int> mp;

int main () {
	scanf ("%d", &n);
	ll mini;
	mini = 1e18;
	ll val = 0;
	for (int i = 0; i < n-1; i++) {
		scanf ("%d", &q[i]);
		val += q[i];
		mini = min (mini, val);
	}
	
	a[0] = max (0ll, -mini) + 1;
	mp[a[0]]++;
	for (int i = 0; i < n-1; i++) {
		a[i+1] = a[i] + q[i];
		mp[a[i+1]]++;
	}
	for (auto p : mp)
		if (p.x < 1 or p.x > n or p.y != 1) {
			printf ("-1\n");
 			return 0;
		}
		
	for (int i = 0; i < n; i++)
		printf ("%lld%c", a[i], " \n"[i==n-1]);

	return 0;
}
