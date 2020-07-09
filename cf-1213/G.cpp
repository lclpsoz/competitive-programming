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

const int N = 2e5 + 10;

int n, m;
int sz[N], link[N];
vector<pii> edges[N];
ll arr[N];

int find(int x){
	if(link[x] == x) return x;
	return link[x] = find(link[x]);
}

bool same(int x, int y) { return find(x) == find(y); }

void unite(int u, int v){
	u = find(u), v = find(v);
	if(sz[u] > sz[v]) swap(u, v);
	sz[v] += sz[u];
	link[u] = v;
}

int main () {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) sz[i] = 1, link[i] = i;
	for(int i = 0; i < n-1; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		edges[w].push_back({u, v});
	}

	for (int w = 1; w <= 2e5; w++) {
		arr[w] = arr[w-1];
		for(auto e : edges[w]) {
			if(!same(e.x, e.y)) {
				ll szNow = sz[find(e.x)];
				arr[w] -= (szNow*(szNow-1))/2;
				szNow = sz[find(e.y)];
				arr[w] -= (szNow*(szNow-1))/2;
				unite(e.x, e.y);
				szNow = sz[find(e.y)];
				arr[w] += (szNow*(szNow-1))/2;
			}
		}
	}
	while (m--) {
		int q;
		scanf("%d", &q);
		printf("%lld ", arr[q]);
	}
	putchar('\n');
	
	return 0;
}
