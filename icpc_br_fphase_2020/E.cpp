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

const int N = 1e5 + 10, K = 20;
int ans[N], y[N], n, m;
vi adj[N];
ordered_set<pii> st;
vpii a[N];
int parent[N][K];

void dfs(int v, int p)
{
	for(auto [l, q] : a[v]) st.insert({l, q});
	ans[v] = (int)st.order_of_key({y[v], N});
	for(auto u : adj[v])
	{
		if(u == p) continue;
		dfs(u, v);
	}
	for(auto [l, q] : a[v]) st.erase({l, q});
}

int check(int v, int r)
{
	for(int i = K - 1; i >= 0; i--)
		if(y[parent[v][i]] <= r)
			v = parent[v][i];
	return v;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> n >> m;

	for(int i = 0; i < n; i++)
	{
		int p;
		cin >> y[i] >> p;
		--p;
		adj[i].emplace_back(p); 
		adj[p].emplace_back(i); 
		parent[i][0] = p;
	}

	for(int j = 1; j < K; j++)
		for(int i = 0; i < n; i++)
			parent[i][j] = parent[parent[i][j - 1]][j - 1];

	for(int i = 0; i < m; i++)
	{
		int o, l, r;
		cin >> o >> l >> r;
		--o;
		o = check(o, r);
		a[o].emplace_back(l, i);
	}

	dfs(0, 0);

	for(int i = 0; i < n; i++)
		cout << ans[i] << " \n"[i == n - 1];

	return 0;
}
