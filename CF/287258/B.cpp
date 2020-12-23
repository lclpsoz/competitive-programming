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
pii adj[N];
int level[N], cnt, deg[N];
double rr[N], hh[N];

void dfs(int v, int d = 0)
{
	level[v] = d;
	auto [l, r] = adj[v];
	if(!l)
	{
		hh[v] = cnt;
		rr[v] = 1 + cnt * 2;
		cnt++;
	}
	else
	{
		dfs(l, d + 1);
		dfs(r, d + 1);
		rr[v] = (rr[l] + rr[r]) / 2;
		hh[v] = (hh[l] + hh[r]) / 2;
	}
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(4);

	int tt; cin >> tt;
	while(tt--)
	{
		int n, q;
		cin >> n >> q;
		for(int i = 1; i <= n; i++) adj[i] = pii(0, 0), level[i] = 0, deg[i] = 0;
		cnt = 0;

		for(int i = 1; i <= n; i++)
		{
			int k; cin >> k;
			if(k)
			{
				auto& [l, r] = adj[i];
				cin >> l >> r;
				deg[l]++, deg[r]++;
			}
		}

		int root = 1;
		for(int i = 1; i <= n; i++)
			if(!deg[i]) root = i;

		dfs(root);

		while(q--)
		{
			int r, v, h, u;
			cin >> r >> v >> h >> u;

			double xr = rr[root] * r + hh[root] * h;
			double x, y;
			y = (2 * r + v) * -level[u];
			x = rr[u] * r + hh[u] * h - xr;
			cout << fixed << x << " " << y << '\n';

			// cout << u << ": " << level[u] << endl;
		}
	}

	return 0;
}
