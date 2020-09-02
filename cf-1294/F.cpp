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
set<pii> ans;

void far(int v, int d, int p) {
	if(d > dist) {
		vert = v;
		dist = d;
	}
	for(int u : adj[v])
		if(u != p)
			far(u, d+1, v);
}

bool dfs(int v, int targ, int p) {
	if(v == targ) {
		q.push({v, 0});
		return true;
	} else {
		for(int u : adj[v])
			if(u != p and dfs(u, targ, v)) {
				q.push({u, 0});
				return true;
			}
	}
	return false;
}


bool getPath(int v, int targ, int p) {
	if(v == targ) {
		return true;
	} else {
		for(int u : adj[v]) {
			if(u != p and getPath(u, targ, v)) {
				if(u < v)
					ans.insert({u, v});
				else
					ans.insert({v, u});
				return true;
			}
		}
	}
	return false;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout.precision(10);
	cin >> n;
	for(int i = 1; i <= n-1; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	

	far(1, 1, 1);
	int u = vert;
	dist = 0;
	far(u, 1, u);
	int v = vert;
	dfs(u, v, u);
	q.push({u, 0});

	if(dist == n) {
		cout << n-1 << '\n';
		int ax = 1;
		while(u == ax or v == ax) ++ax;
		cout << u << ' ' << v << ' ' << ax << '\n';
		exit(0);
	}
	memset(vis, 0, sizeof vis);
	int lst = u, maxi = 0;
	while(!q.empty()) {
		pii p = q.front();
		q.pop();
		int vv = p.x;
		int d = p.y;
		if(vis[vv]) continue;
		// cout << "vv = " << vv << " d = " << d << '\n';
		vis[vv] = 1;
		if(d > maxi) {
			maxi = d;
			lst = vv;
		}
		for(int uu : adj[vv]) {
			q.push({uu, d+1});
		}
	}
	// cout << "maxi = " << maxi << " lst = " << lst << '\n';
	memset(vis, 0, sizeof vis);
	getPath(u, v, u);
	memset(vis, 0, sizeof vis);
	getPath(u, lst, u);
	memset(vis, 0, sizeof vis);
	getPath(v, lst, v);
	// for(auto p : ans)
	// 	cout << p.x << ' ' << p.y << '\n';
	while(u == lst or v == lst) {
		lst++;
		if(lst == n) lst = 1;
	}
	cout << LEN(ans) << '\n';
	cout << u << ' ' << v << ' ' << lst << '\n';

	return 0;
}
