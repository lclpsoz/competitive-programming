#include "bits/stdc++.h"
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define LEN(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
using ll = long long;
using llu = long long unsigned;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vpii = vector<pii>;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

const int INF = 1e9;
const int N = 1e5 + 10;

int n, m, k, s, t;
int link[N], sz[N];
vector<int> marked;
vector<int> adj[N];
int vis[N];
int mini_vert[N], mini_dist[N];

int find(int x) {
	if(x == link[x])
		return x;
	return link[x] = find(link[x]);
}

bool same(int x, int y) {
	return find(x) == find(y);
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if(sz[x] > sz[y])
		swap(x, y);
	sz[y] += sz[x];
	link[x] = y;
}

// void dfs(int v, int q) {
// 	if(q < 0) return;
// 	printf("      q = %d, v = %d\n", q, v);
// 	for(auto p : adj[v]) {
// 		if(!vis_edge[p.y]) {
// 			vis_edge[p.y] = 1;
// 			if(!same(v, p.x))
// 				unite(v, p.x);
// 			dfs(p.x, q-1);
// 		}
// 	}
// }
queue<pair<int, pii>> bfs;
queue<pii> bfs2;

bool eval(int q) {
	for(int i = 1; i <= n; i++) {
		link[i] = i;
		sz[i] = 1;
	}
	// printf("q = %d\n", q);
	for(int v : marked) {
		bfs.push({v, {v, 0}});
		mini_vert[v] = v;
		// printf("  mk = %d\n", v);
		// printf("    ");
		// for(int i = 1; i <= n; i++)
		// 	printf("%d%c", find(i), " \n"[i==n]);
		// dfs(v, q);
	}
	while(LEN(bfs)) {
		int v, rep, dist;
		auto now = bfs.front();
		v = now.x;
		rep = now.y.x;
		dist = now.y.y;
		bfs.pop();
		// if(dist and mini_dist[v] == INF and v == t and !same(v, rep))
		// 	unite(rep, v);
		if(vis[v] == q) {
			// printf("    v = %d, rep = %d, mini_d = %d, mini_v = %d, d = %d\n", v, rep, mini_dist[v], mini_vert[v], dist);
			if(mini_dist[v]+dist <= q and !same(rep, mini_vert[v]))
				unite(rep, mini_vert[v]);
			continue;
		}
		vis[v] = q;
		mini_dist[v] = dist;
		mini_vert[v] = rep;
		if(dist < q)
			for(int u : adj[v]) {
				// vis_edge[p.y] = 1;
				// printf("  rep = %d, v = %d, u = %d, dist = %d\n", rep, v, u, dist+1);
				bfs.push({u, {rep, dist + 1}});
			}		
	}
	if(!same(s, t)) {
		bfs2.push({t, 0});
		while(LEN(bfs2)) {
			int v, dist;
			tie(v, dist) = bfs2.front();
			bfs2.pop();
			if(same(s, v)) {
				unite(s, t);
				break;
			}
			if(vis[v] == INF+q) continue;
			vis[v] = INF+q;
			if(dist < q)
				for(int u : adj[v])
					bfs2.push({u, dist+1});
		}
		while(!bfs2.empty()) bfs2.pop();
	}
	// printf("%d %d %d %d\n", s, t, find(s), find(t));
	return same(s, t);
}

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= k; i++) {
		int x;
		scanf("%d", &x);
		marked.push_back(x);
	}

	for(int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		if(u > v) swap(u, v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	scanf("%d %d", &s, &t);
	int l, r;
	l = 1, r = 2*n+10;
	while(l < r) {
		int md = (l+r)/2;
		if(eval(md))
			r = md;
		else
			l = md+1;
	}
	if(r == 2*n+10)
		printf("-1\n");
	else
		printf("%d\n", l);

	return 0;
}
