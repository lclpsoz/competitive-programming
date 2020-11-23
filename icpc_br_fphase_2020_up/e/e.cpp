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

const int N = 1e5 + 10;

int age[N];
vpii parties[N], parties_o[N];
vpii actives;
int ans[N];
vi adj[N];
ll bit[N];

ll sum(int p) {
	ll ret = 0;
	for(int i = p; i; i -= i&-i)
		ret += bit[i];
	return ret;
}

void add(int p, int v) {
	for(int i = p; i < N; i+=i&-i)
		bit[i] += v;
}

void solve(int v, int p) {
	for(pii party : parties[v])
		add(party.x, 1);
	ans[v] = sum(age[v]);
	for(int u : adj[v])
		solve(u, v);
	for(pii party : parties[v])
		add(party.x, -1);
}	

void dfs_up(int v, int p) {
	actives.push_back({-age[v], v});
	for(pii party : parties_o[v]) {
		auto it = lower_bound(ALL(actives), make_pair(-party.y, -INF<int>));
		parties[it->y].push_back(party);
	}
	for(int u : adj[v]) {
		dfs_up(u, v);
	}
	actives.pop_back();
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		int p;
		cin >> age[i];
		cin >> p;
		if(i>1)
			adj[p].push_back(i);
	}

	while(m--) {
		int o, l, r;
		cin >> o >> l >> r;
		parties_o[o].push_back({l, r});
	}
	dfs_up(1, 1);

	solve(1, 1);
	for(int i = 1; i <= n; i++)
		cout << ans[i] << " \n"[i==n];

	return 0;
}
