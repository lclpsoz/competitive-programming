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

int n, a[N], ans;
bool not_prime[N], vis[N];
vector<int> primes, verts[N];
vector<int> fullAdj[N], adj[N];

void sieve () {
	for (int i = 2; i*i < N; i++)
		if (!not_prime[i]) {
			primes.push_back (i);
			for (int j = i*i; j < N; j+=i)
				not_prime[j] = true;
		}
}

pii dfs (int v, int parent, int depth) {
	vis[v] = true;
	pii ret = {v, depth};
	for (int u : adj[v])
		if (u != parent) {
			pii now = dfs (u, v, depth + 1);
			if (now.y > ret.y)
				ret = now;
		}
		
	return ret;
}

int main () {
	sieve ();
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf ("%d", &x);
		if (x > 1)
			ans = 1;
		a[i] = x;
		for (int p : primes)
			if (x%p == 0) {
				verts[p].push_back (i);
				while (x%p == 0) x/=p;
			}
		if (x > 1)
			verts[x].push_back (i);
	}
	
	for (int i = 0; i < n-1; i++) {
		int x, y;
		scanf ("%d %d", &x, &y);
		fullAdj[x].push_back (y);
		fullAdj[y].push_back (x);	
	}
	
	for (int i = 0; i < N; i++)
		if (len (verts[i]) > 1) {
			memset (vis, 0, sizeof vis);
			for (int v : verts[i])
				for (int u : fullAdj[v]) {
					if (a[u]%i == 0)
						adj[v].push_back (u);
				}
					
			for (int v : verts[i]) {
				if (vis[v]) continue;
				int dV = dfs (v, v, 1).x;
				ans = max (ans, dfs (dV, dV, 1).y);
			}
			
			for (int v : verts[i])
				adj[v].clear();
		}
		
	printf ("%d\n", ans);

	return 0;
}
