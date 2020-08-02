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

const int N = 2e5 + 10;

int n, m, k, s, t;
int link[N], sz[N];
vector<int> marked;
vector<pii> adj[N];
bool vis_edge[N], marked_vert[N];
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

void dfs(int v, int q) {
	if(q < 0) return;
	printf("      q = %d, v = %d\n", q, v);
	for(auto p : adj[v]) {
		if(!vis_edge[p.y]) {
			vis_edge[p.y] = 1;
			if(!same(v, p.x))
				unite(v, p.x);
			dfs(p.x, q-1);
		}
	}
}

bool eval(int q) {
	memset(vis_edge, 0, sizeof(vis_edge));
	memset(marked_vert, 0, sizeof(marked_vert));
	memset(mini_vert, -1, sizeof(mini_vert));
	for(int i = 1; i <= n; i++) {
		link[i] = i;
		mini_dist[i] = 1e9;
		sz[i] = 1;
	}
	printf("q = %d\n", q);
	queue<pair<int, pii>> bfs;
	for(int v : marked) {
		bfs.push({v, {v, q}});
		mini_vert[v] = v;
		mini_dist[v] = 0;
		// printf("  mk = %d\n", v);
		// printf("    ");
		// for(int i = 1; i <= n; i++)
		// 	printf("%d%c", find(i), " \n"[i==n]);
		// dfs(v, q);
	}
	while(LEN(bfs)) {
		int v, rep, qnt;
		auto now = bfs.front();
		v = now.x;
		rep = now.y.x;
		qnt = now.y.y;
		bfs.pop();
		--qnt;
		for(auto p : adj[v]) {
			// vis_edge[p.y] = 1;
			if(marked_vert[rep] and marked_vert[p.x] and !same(rep, p.x))
				unite(rep, p.x);
			printf("  rep = %d, v = %d, p.x = %d\n", rep, v, p.x);
			if(qnt)
				bfs.push({p.x, {rep, qnt-1}});
		}		
	}
	for(int i = 1; i <= n; i++)
		printf("%d%c", find(i), " \n"[i==n]);
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

	map<pii, int> mp;
	for(int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		if(u > v) swap(u, v);
		mp[{u, v}] = i;
	}
	for(auto p : mp) {
		adj[p.x.x].push_back({p.x.y, p.y});
		adj[p.x.y].push_back({p.x.x, p.y});
	}
	scanf("%d %d", &s, &t);
	int l, r;
	l = 1, r = m;
	while(l < r) {
		int md = (l+r)/2;
		if(eval(md))
			r = md;
		else
			l = md+1;
	}
	printf("%d\n", l);

	return 0;
}
