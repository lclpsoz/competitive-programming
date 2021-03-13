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

inline int fcmp (ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod (ll x, int m = MOD) {
	int ret = (int)x%m;
	if (ret < 0)
		ret += m;
	return ret;
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e5 + 10;
int n, k, ans;
bool ap[N], good[N];
int h[N];
vi adj[N];

void dfs(int v, int p)
{
	h[v] = ap[v];
	for(auto u : adj[v])
	{
		if(u == p) continue;
		dfs(u, v);
		h[v] += h[u];
	}	
}

void dfs(int v, int p, bool hp)
{
	vector<bool> pre, suf;
	pre.emplace_back(false);
	for(auto u : adj[v])
	{
		if(u == p) continue;
		pre.emplace_back(h[u]);
		suf.emplace_back(h[u]);

	}
	suf.emplace_back(false);

	for(int i = 1; i < LEN(pre); i++)
		pre[i] = pre[i - 1] || pre[i];
	for(int i = LEN(suf) - 2; i >= 0; i--)
		suf[i] = suf[i + 1] || suf[i];

	if(ap[v]) good[v] = true;
	else
	{
		int i = 0;
		for(auto u : adj[v])
		{
			if(u == p) continue;
			if((pre[i] || suf[i + 1] || hp) && h[u])
				good[v] = true;
			i++;
		}
	}
	
	int i = 0;
	for(auto u : adj[v])
	{
		if(u == p) continue;
		dfs(u, v, hp || ap[v] || pre[i] || suf[i + 1]);
		i++;
	}
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	cin >> n >> k;
	for(int i = 1; i < n; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}

	for(int i = 0; i < k; i++)
	{
		int a; cin >> a;
		ap[a] = true;
	}

	dfs(1, 0);
	dfs(1, 0, false);

	cout << accumulate(good + 1, good + n + 1, 0) << endl;

	return 0;
}
