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

const int N = 1e5 + 10;

int n, k;
vector<int> adj[N];
int vis[N];

int main () {
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n-1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> now, nxt;
	for(int i = 1; i <= n; i++)
		if(len(adj[i]) == 1) {
			now.push_back(i);
			vis[i] = k;
		}
	--k;
	while(k and len(now)) {
		int v = now.back();
		// printf("v = %d\n", v);
		now.pop_back();
		for(int u : adj[v])
			if(vis[u] == 0) {
				vis[u] = k;
				nxt.push_back(u);
			} else if(vis[u] == k+1) {
				// printf("  v = %d, u = %d\n", v, u);
				printf("No\n");
				exit(0);
			}
		if(len(now) == 0) {
			for(int v : nxt) {
				int q = 0;
				for(int u : adj[v])
					if(vis[u] == k+1)
						++q;
				if(q < 3 or len(adj[v]) != q+1) {
					printf("No\n");
					exit(0);
				}
			}
			--k;
			now = nxt;
			nxt.clear();
		}
	}
	int center = -1;
	for(int i = 1; i <= n; i++)
		if(vis[i] == 0) {
			if(center == -1)
				center = i;
			else {
				printf("No\n");
				exit(0);
			}
		}
	if(len(adj[center]) >= 3)
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}
