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

const int N = 2e4 + 10, K = 16; 
ll dist[K][K];
ll dp[1 << K][K][2];
int sites[K];

using node = pair<ll, int>;
priority_queue<node, vector<node>, greater<node>> pq;

vpii adj[N];
bitset<N> vis;

ll dijkstra(int s, int t)
{
	while(!empty(pq)) pq.pop();

	vis = 0;
	pq.emplace(0, s);
	while(!empty(pq))
	{
		auto [w, v] = pq.top();
		pq.pop();

		if(vis[v]) continue;
		vis[v] = 1;
		
		if(v == t)
			return w;

		for(auto [u, c] : adj[v])
			pq.emplace(c + w, u);
	}
	return 1e18;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n, p, m, g, t;
	cin >> n >> p >> m >> g >> t;

	for(int i = 0; i < p; i++)
	{
		int k;
		cin >> sites[i] >> k;
		g -= k;
	}

	for(int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
	}

	for(int i = 0; i < p; i++)
		for(int j = 0; j < p; j++)
			dist[i][j] = dijkstra(sites[i], sites[j]);

	for(int i = 0; i < p; i++)
		for(int msk = 0; msk < (1 << p); msk++)
			dp[msk][i][0] = dp[msk][i][1] = (ll)1e18;	
	
	ll ans0 = (ll)1e18;
	ll ans1 = (ll)1e18;

	for(int msk = 0; msk < (1 << p); msk++)
	{
		for(int i = 0; i < p; i++)
		{
			if(!msk)
			{
				dp[1 << i][i][0] = dijkstra(0, sites[i]);
				dp[1 << i][i][1] = t;
				continue;
			}

			if(msk + 1 == (1 << p))
			{
				ll d = dijkstra(sites[i], 0);
				ans0 = min(ans0, dp[msk][i][0] + d);
				ans1 = min(ans1, dp[msk][i][0] + t);
				ans1 = min(ans1, dp[msk][i][1] + d);
			}

			if(!(msk & (1 << i))) continue;

			for(int j = 0; j < p; j++)
			{
				if(msk & (1 << j)) continue;
				dp[msk | (1 << j)][j][0] = min(dp[msk | (1 << j)][j][0], dp[msk][i][0] + dist[i][j]);
				dp[msk | (1 << j)][j][1] = min(dp[msk | (1 << j)][j][1], dp[msk][i][0] + t);
				dp[msk | (1 << j)][j][1] = min(dp[msk | (1 << j)][j][1], dp[msk][i][1] + dist[i][j]);
			}
		}
	}

	// cout << ans0 << " " << ans1 << " <= " << g << endl;

	if(ans0 <= g) cout << "possible without taxi" << endl;
	else if(ans1 <= g) cout << "possible with taxi" << endl;
	else cout << "impossible" << endl;
	
	return 0;
}
