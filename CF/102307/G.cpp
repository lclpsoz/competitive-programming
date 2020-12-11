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

const int N = 1e4 + 10;

int n, k;
int nxt[N];
// vector<int> bef[N];
int qnt_pre[N];
bitset<N> vis;
int path_len[N];
vector<int> top_sort;

int dfs_path(int v) {
	if(path_len[v])
		return path_len[v];
	if(nxt[v])
		return path_len[v] = dfs_path(nxt[v]) + 1;
	else
		return path_len[v] = 1;
}

void dfs_top_sort(int v) {
	if(vis[v]) return;
	vis[v] = 1;
	if(nxt[v])
		dfs_top_sort(nxt[v]);
	top_sort.push_back(v);
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> n >> k;
	for(int v = 1; v <= n; v++) {
		int u;
		cin >> u;
		nxt[v] = u;
		qnt_pre[u]++;
		// bef[u].push_back(v);
	}
	for(int v = 1; v <= n; v++)
		if(!vis[v])
			dfs_top_sort(v);
	reverse(ALL(top_sort));

	for(int v : top_sort)
		if(!path_len[v])
			dfs_path(v);

	set<pair<int, pii>> st;
	for(int v = 1; v <= n; v++)
		st.insert({qnt_pre[v], {-path_len[v], v}});

	map<int, int> mp;
	for(int ans = 1;; ans++) {
		
		// cout << "  i = " << ans << '\n';
		for(int i = 0; LEN(st) and st.begin()->x == 0 and i < k; i++) {
			int v = st.begin()->y.y;
			// cout << "    v = " << v << ", maxi = " << st.begin()->y.x << '\n';
			st.erase(st.begin());
			int u = nxt[v];
			if(u == 0) continue;
			if(mp.count(u))
				mp[u]++;
			else
				mp[u] = 1;
			qnt_pre[u]--;
		}
		if(LEN(st) == 0) {
			cout << ans << '\n';
			exit(0);
		}
		for(auto p : mp) {
			int v = p.x;
			st.erase({qnt_pre[p.x]+p.y, {-path_len[v], v}});
			st.insert({qnt_pre[v], {-path_len[v], v}});
		}
		mp.clear();
	}

	return 0;
}
