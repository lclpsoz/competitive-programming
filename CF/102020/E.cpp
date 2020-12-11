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

const int MOD = 1e9 + 7;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

const int N = 2e5 + 10;
int dp1[N][2], dp2[N][2];
vi adj[N];

inline int add(int a, int b)
{
	return (a + b) % MOD;
}
inline int mul(int a, int b)
{
	return int((a * 1LL * b) % MOD);
}

int tot, sum;

void dfs(int v, int p)
{
	dp1[v][0] = 1;

	for(auto u : adj[v])
	{
		if(u == p) continue;
		dfs(u, v);
		dp1[v][1] = add(dp1[v][1], mul(add(dp1[v][0], MOD - 1), dp1[u][0]));
		dp2[v][1] = add(dp2[v][1], add(mul(dp2[v][0], dp1[u][0]), mul(add(dp2[u][0], dp1[u][0]), add(dp1[v][0], MOD - 1))));

		dp1[v][0] = add(dp1[v][0], dp1[u][0]);
		dp2[v][0] = add(dp2[v][0], add(dp2[u][0], dp1[u][0]));
	}

	// cout << v << ": " << dp1[v][0] << ", " << dp1[v][1] << endl;
	// cout << v << ": " << dp2[v][0] << ", " << dp2[v][1] << endl;

	tot = add(tot, dp1[v][0]);
	tot = add(tot, dp1[v][1]);

	sum = add(sum, dp2[v][0]);
	sum = add(sum, dp2[v][1]);
}

int fexp(int b, ll x)
{
	int ans(1);
	while(x)
	{
		if(x & 1LL) ans = mul(ans, b);
		b = mul(b, b);
		x >>= 1LL;
	}
	return ans;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n; cin >> n;

	for(int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}

	dfs(1, 1);

	// cout << sum << " / " << tot << endl;

	cout << mul(sum, fexp(tot, MOD - 2)) << endl;

	return 0;
}
