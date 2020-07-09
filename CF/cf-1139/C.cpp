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

const int MOD = 1e9+7;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e5+10;

int n, k;
int id;
vector<pii> adj[N];
int groups[N];
int powN[200];

void dfs (int v, int p, int now) {
	groups[now]++;
	for (pii pp : adj[v]) {
		int u = pp.x;
		int typ = pp.y;
		if (u != p) {
			if (typ)
				dfs (u, v, ++id);
			else
				dfs (u, v, now);
		}
	}
}

int main () {
	scanf ("%d %d", &n, &k);
	id = 1;
	for (int i = 0; i < n-1; i++) {
		int a, b, typ;
		scanf ("%d %d %d", &a, &b, &typ);
		adj[a].push_back ({b, typ});
		adj[b].push_back ({a, typ});
	}
	dfs (1, 1, 1);
	powN[0] = 1;
	for (int i = 1; i <= k; i++)
		powN[i] = (powN[i-1] * 1LL * n) % MOD;
	
	ll ans = 0;
	for (int i = 1; i <= id; i++) {
		int now = groups[i], rest = n-now;
		int pNow = now;
		ll acu = 0;
		for (int j = 1; j < k; j++) {
			acu += (pNow * 1LL * powN[k-j-1])%MOD;
			pNow = (pNow * 1LL * now)%MOD;
		}
		ans = ((acu*1LL*rest)%MOD + ans)%MOD;
	}

	printf ("%lld\n", ans);
		
	return 0;
}
