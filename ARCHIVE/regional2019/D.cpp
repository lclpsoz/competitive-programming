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

const int N = 1e5 + 10;

int n, k;
vector<int> adj[N];
int parent[N];
int leafs[N];

int main () {
	scanf ("%d %d", &n, &k);
	for (int i = 2; i <= n; i++) {
		int p;
		scanf ("%d", &p);
		adj[p].push_back (i);
		parent[i] = p;
		leafs[p]++;
	}

	queue<pii> q;
	for (int i = 1; i <= n; i++)
		if (leafs[i] == 0)
			q.push ({i, 0});

	k = len(q)-k;
	int ans = n;
	while (!q.empty() and k) {
		int v = q.front().x, qnt = q.front().y;
		q.pop();
		if (v == 0) continue;
		if (leafs[v] > 1) {
			// printf ("%d: %d\n", v, qnt);
			leafs[v]--;
			ans -= qnt;
			--k;
		} else
			q.push ({parent[v], qnt+1});
	}
	printf ("%d\n", ans);


	return 0;
}
