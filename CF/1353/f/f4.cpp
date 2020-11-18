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

template<typename T>
const T INF = (is_same<T, int>::value ? 1e9 : 1e18);
const ld EPS = 1e-9;
const int MOD = 1;

inline int fcmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

ll dp[105][105];

ll dijkstra(vector<vi> &adj, vector<vector<ll>> &mat, int st, int en, int n, int n_cols) {
	vector<ll> dist(n+5, INF<ll>);
	set<pair<ll, pair<int, ll>>> dij;
	dij.insert({0LL, {1, mat[0][1]}});
	dist[st] = 0LL;
	while(LEN(dij)) {
		ll d = dij.begin()->x;
		int v = dij.begin()->y.x;
		int x = (v-1)/n_cols+1, y = ((v-1)%n_cols)+1;
		int len_path_v = x-1 + y-1 + 1;
		ll val_last = dij.begin()->y.y;
		dij.erase(dij.begin());
		// cout << "  v = " << v << ", coord = " << x << ' ' << y << '\n';
		// cout.flush();
		if(dist[v] != d) continue;
		for(int u : adj[v]) {
			int u_x = (u-1)/n_cols+1;
			int u_y = ((u-1)%n_cols)+1;
			ll val_now = mat[u_x-1][u_y];

			ll cost = 0;
			// cout << "      vals = " << val_last << " vs " << val_now << '\n';
			if(val_now > val_last+1) {
				cost = val_now-val_last-1;
				val_now = val_last+1;
			}
			else if(val_now < val_last+1)
				continue;

			// cout << "    u = " << u << ", cost = " << cost << '\n';
			if(dist[v] < INF<ll> and dist[v]+cost < dist[u]) {
				dist[u] = dist[v]+cost;
				dij.insert({dist[u], {u, val_now}});
			}
		}
		// cout << '\n';
	}
	// for(int i = 1; i <= n; i++) {
	// 	if((i-1)%n_cols == 0) cout << '\n';
	// 	cout << dist[i] << ' ';
	// }
	// cout << '\n';
	return dist[en];
}

// void brute(vector<vector<ll>> &mat, int n, int m) {
// 	// vector<vector<ll>> bst;
// 	int bst =  0;
// 	ll val = INF<ll>;
// 	for(int i = 0; i < (1<<(n+m-2)); i++) {
// 		if(__builtin_popcount(i) != n-1) continue;
// 		vector<vector<ll>> now = mat;
// 		int p = 0;
// 		int x = 0, y = 1;
// 		ll val_now = 0;
// 		while(p < (n+m-2)) {
// 			if(i&(1<<p)) {
// 				if(now[x+1][y] > now[x][y]+1) {
// 					val_now += now[x+1][y]-now[x][y]-1;
// 					now[x+1][y] = now[x][y]+1;
// 				} else if(now[x+1][y] < now[x][y]+1) {
// 					val_now += (p+1)*(now[x][y]-now[x+1][y]+1);
// 				}
// 				x++;
// 			} else {
// 				if(now[x][y+1] > now[x][y]+1) {
// 					val_now += now[x][y+1]-now[x][y]-1;
// 					now[x][y+1] = now[x][y]+1;
// 				} else if(now[x][y+1] < now[x][y]+1) {
// 					val_now += (p+1)*(now[x][y]-now[x][y+1]+1);
// 				}
// 				y++;
// 			}
// 			p++;
// 			if(i == 240)
// 				cout << x << ' ' << y << ' ' << val_now << '\n';
// 				cout.flush();
// 			assert(x < n and y <= m);
// 		}
// 		if(val_now < val) {
// 			bst = i;
// 			val = val_now;
// 		}
// 		cout << bitset<8>(i) << ' ' << i << ' ' << val_now << '\n';
// 	}
// 	cout << bitset<8>(bst) << '\n';
// 	cout << val << '\n';
// }

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int t;
	cin >> t;
	while(t--) {
		// cout << "t = " << t << '\n';
		int n, m;
		cin >> n >> m;
		vector<vi> adj(n*m+10);
		vector<vector<ll>> mat(n+1, vector<ll>(m+10));
		for(int i = 0; i < n; i++)
			for(int j = 1; j <= m; j++)
				cin >> mat[i][j];
		for(int i = 0; i < n; i++)
			for(int j = 1; j <= m; j++) {
				int v = i*m + j;
				if(j < m) {
					int u = v+1;
					adj[v].push_back(u);
				}
				if(i < n-1) {
					int u = (i+1)*m + j;
					adj[v].push_back(u);
				}
			}
		// cout << dijkstra(adj, mat, 1, n*m, n*m, m) << '\n';
		ll st_val = mat[0][1];
		ll en_val = mat[n-1][m];
		int op = n-1 + m-1;
		ll base = 0;
		if(st_val+op > en_val) {
			base = (st_val+op)-en_val;
			st_val -= base;
			mat[0][1] = st_val;
		}
		else if(st_val+op < en_val) {
			base += en_val-(st_val+op);
			en_val -= base;
			mat[n-1][m] = en_val;
		}
		set<ll> st_vals;
		for(int i = 0; i < n; i++)
			for(int j = 1; j <= m; j++) {
				int op_now = i + j-1;
				ll st_now = mat[i][j]-op_now;
				// cout << st_now << " vs " << st_val << '\n';
				if(st_now <= st_val)
					st_vals.insert(st_now);
			}
		ll ans = INF<ll>;
		// st_vals.insert(-1000000000000000);
		for(ll st_now : st_vals) {
			ll delta = st_val-st_now;
			mat[0][1] = st_val-delta;
			mat[n-1][m] = en_val-delta;

			ll now = base + 2*delta + dijkstra(adj, mat, 1, n*m, n*m, m);
			// cout << delta << ":\t\t" << now << '\n';
			ans = min(ans, now);
			// cout << delta << ": " << now << '\n';
		}
		cout << ans << '\n';
		// brute(mat, n, m);
	}

	return 0;
}
