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
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int INF = 1e9 + 10;
const int N = 1e5 + 10;

int ans[N];
vector<pii> adj[N];

void dfs(int v, int maxi) {
	if(ans[v] != INF)
		return;
	ans[v] = maxi;
	for(pii p : adj[v])
		dfs(p.x, min(maxi, p.y));
}

int main () {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) ans[i] = INF;
	for(int i = 0; i < n-1; i++) {
		int v, u, c;
		scanf("%d %d %d", &v, &u, &c);
		adj[v].push_back({u, c});
		adj[u].push_back({v, c});
	}
	dfs(n, INF-1);
	for(int i = 1; i < n; i++)
		printf("%d%c", ans[i], " \n"[i==n-1]);

	return 0;
}
