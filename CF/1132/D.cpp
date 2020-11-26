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

const ll INF = 2e12 + 1000;
const int N = 2e5+10;

int n, k;
ll a[N];
int b[N];
ll ax[N], delta;
set<pii> st;

bool check (ll power) {
// 	printf ("power: %lld\n", power);
	st.clear();
	for (int i = 1; i <= n; i++)
		ax[i] = a[i];
	for (int i = 1; i <= n; i++) {
		ll tm = 1;
		delta = ax[i]/b[i];
		tm += delta;
		if (tm < k) {
			ax[i] -= b[i]*delta;
			st.insert ({(int)tm, i});
		}
	}
	
	int now = 1;
	while (!st.empty()) {
		ll tm = st.begin()->x;
// 		printf ("tm: %lld\n", tm);
		if (tm < now)
			return false; // Two needs at the same time
		int id = st.begin()->y;
// 		printf ("id: %d\n", id);
		
		st.erase (st.begin());
		ax[id] += power;
		delta = ax[id]/b[id];
		tm += delta;
		if (tm < k) {
			ax[id] -= b[id]*delta;
			st.insert ({(int)tm, id});
		}
		++now;
	}
	
	return true;
}

int main () {
	scanf ("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf ("%lld", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf ("%d", &b[i]);
	
	ll l = 0, r = INF;
	while (l < r) {
		ll md = (l+r)/2;
// 		printf ("md: %lld\n", md);
		if (check (md))
			r = md;
		else
			l = md+1;
	}
	
	if (l == INF)
		l = -1;
	printf ("%lld\n", l);

	return 0;
}
