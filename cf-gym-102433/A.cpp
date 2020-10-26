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

const int N = 1e5 + 10;
vpii adj[N];
int n, t[N];
int sz[N];
ll ans1[N], ans2[N], dsum[N], tsum[N];

void dfs(int v, int p)
{
	sz[v] = 1;
	tsum[v] = t[v];

	for(auto [u, w] : adj[v])
	{
		if(u == p) continue;
		dfs(u, v);
		sz[v] += sz[u];
		dsum[v] += dsum[u] + w * sz[u];
		tsum[v] += tsum[u];
		ans1[v] += tsum[u] * w + ans1[u];
	}
}

void dfs(int v, int p, ll ds, ll ts, ll ap, int ww)
{
	ans1[v] += ts * ww + ap;
	ans2[v] += t[v] * (dsum[v] + ds);

	for(auto [u, w] : adj[v])
	{
		if(u == p) continue;
		ll nts = ts + tsum[v] - tsum[u];
		ll nds = ds + (dsum[v] - dsum[u] - w * sz[u]) + (n - sz[u]) * w;
		ll nap = ans1[v] - (ans1[u] + tsum[u] * w);
		dfs(u, v, nds, nts, nap, w);
	}
}


int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> n;

	for(int i = 1; i <= n; i++)
		cin >> t[i];

	for(int i = 1; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
	}

	dfs(1, 1);
	dfs(1, 1, 0, 0, 0, 0);

	for(int i = 1; i <= n; i++)
		cout << ans1[i] + ans2[i] << '\n';

	return 0;
}
