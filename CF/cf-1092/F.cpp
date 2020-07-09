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

const int N = 2e5+100;

int n, a[N];
vector<int> adj[N];
ll ans;

pair<ll, ll> preProcess (int v, int p, ll acu, ll elems) {
	ll r = 0, rElems = 0;
	for (int u : adj[v]) {
		if (u != p) {
			pair<ll, ll> p = solve (u, v, elems+acu+a[v], elems+a[v]);
			r += p.x;
			rElems += p.y;
		}
	}
	
	r = r + acu;
	
	for (int u : adj[v]) {
		if (u != p) {
			ans = max (ans, solve (u, v, r, r)., ;
			
		}
	}
	ans = max (ans, r);
	
	printf ("%d:\tacu: %3lld,\telems: %3lld,\tr: %3lld,\trE: %3lld\n", v, acu, elems, r, rElems);
	
// 	r += acu;
	return {r + rElems + a[v], rElems + a[v]};
}



int main () {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf ("%d", &a[i]);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf ("%d %d", &x, &y);
		adj[x].push_back (y);
		adj[y].push_back (x);
	}
	
	solve (1, 1, 0, 0);
	printf ("%lld\n", ans);

	
	
	return 0;
}
