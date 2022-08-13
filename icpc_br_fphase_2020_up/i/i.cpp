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
const int MOD = 1e9 + 7;

inline int fcmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

const int DBG = 1;

const int N = 1e5 + 10;

vi adj[N];
int mult[N];
int dp[N][2], prod_v[N];

int pow_mod(int b, int p, int m = MOD) {
	int ret = 1;
	while(p) {
		if(p&1) ret = (ret * 1LL * b)%m;
		p>>=1;
		b = (b * 1LL * b)%m;
	}
	return ret;
}

int inv_mod(int b, int m = MOD) {
	return pow_mod(b, m-2);
}

void dfs_mult(int v) {
	while(LEN(adj[v]) == 1) {
		mult[adj[v][0]] = 0;
		adj[v].swap(adj[adj[v][0]]);
		mult[v]++;
	}
	for(int u : adj[v])
		dfs_mult(u);
}

bool is_leaf(int v) {
	return LEN(adj[v]) == 0;
}

void solve(int v) {
	if(is_leaf(v))
		dp[v][1] = 1, dp[v][0] = mult[v];
	else {
		int prod = 1;
		for(int u : adj[v]) {
			solve(u);
			prod = (prod * 1LL * dp[u][0])%MOD;
		}

		int &ret = dp[v][0];
		int &ret_1 = dp[v][1];
		for(int u : adj[v])
			ret = (ret + ((prod*1LL*inv_mod(dp[u][0]))%MOD * 1LL * dp[u][1]))%MOD;
		int ax_ret = ret;
		ret = (ret * 1LL * mult[v])%MOD;
		ret = (ret + prod)%MOD;

		prod = 1;
		for(int u : adj[v])
			prod = (prod * 1LL * dp[u][0])%MOD;
		int sum = 0;
		for(int u : adj[v])
			sum = (sum + (prod*1LL*inv_mod(dp[u][0]))%MOD * 1LL * dp[u][1])%MOD;
		for(int u : adj[v])
			ret_1 = (ret_1 + (mod(sum-((prod*1LL*inv_mod(dp[u][0]))%MOD * 1LL * dp[u][1])%MOD)*1LL*inv_mod(dp[u][0]))%MOD*1LL*dp[u][1])%MOD;
		ret_1 = (ret_1 * 1LL * mult[v])%MOD;
		ret_1 = (ret_1 + ax_ret)%MOD;
	}
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n;
	cin >> n;
	mult[1] = 1;
	for(int i = 2; i <= n; i++) {
		int p;
		cin >> p;
		adj[p].push_back(i);
		mult[i] = 1;
	}
	dfs_mult(1);
	// fill_lf(1);
	solve(1);
	if(DBG) {
		for(int i = 1; i<=n; i++)
			if(mult[i])
				cout << "mult[" << i << "] = " << mult[i] << '\n';
		cout << '\n';
		// for(int i = 1; i<=n; i++)
		// 	if(mult[i])
		// 		cout << "lf[" << i << "] = " << lf[i] << '\n';
		// cout << '\n';
		for(int i = 1; i<=n; i++)
			if(mult[i])
				cout << "dp[" << i << "] = " << dp[i][0] << ' ' << dp[i][1] << '\n';
		cout << '\n';
	}
	
	cout << dp[1][0] << '\n';

	return 0;
}
