#include "bits/stdc++.h"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/pb_ds/assoc_container.hpp"
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

int n;
vector<int> adj[N];
int dist = 0, vert;
bool vis[N];
queue<pii> q;

void far(int v, int d) {
	if(vis[v]) return;
	// cout << v << ' ' << d << '\n';
	if(d > dist) {
		vert = v;
		dist = d;
	}
	vis[v] = 1;
	for(int u : adj[v]) {
		far(u, d+1);
	}
}

bool dfs(int v, int targ) {
	if(vis[v]) return 0;
	vis[v] = 1;
	if(v == targ) {
		q.push({v, 0});
		return true;
	} else {
		for(int u : adj[v])
			if(dfs(u, targ)) {
				q.push({u, 0});
				return true;
			}
	}
	return false;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout.precision(10);
	cin >> n;
	--n;
	while(n--) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	

	far(1, 1);
	memset(vis, 0, sizeof vis);
	int u = vert;
	dist = 0;
	far(u, 1);
	int v = vert;
	memset(vis, 0, sizeof vis);
	dfs(u, v);

	memset(vis, 0, sizeof vis);
	int ans = u, maxi = 0;
	while(!q.empty()) {
		pii p = q.front();
		q.pop();
		int v = p.x;
		int d = p.y;
		if(vis[v]) continue;
		vis[v] = 1;
		if(d > maxi) {
			maxi = d;
			ans = v;
		}
		for(int u : adj[v]) {
			q.push({u, d+1});
		}
	}
	cout << maxi+dist-1 << '\n';
	cout << u << ' ' << v << ' ' << ans << '\n';

	return 0;
}
