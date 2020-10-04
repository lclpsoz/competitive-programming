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
int adj[N];
int pre[N];
int maxi_prof[N];
set<pair<int, pii>> st;

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);

	cin >> n >> k;
	for(int i = 1; i<=n; i++) {
		int v;
		cin >> v;
		adj[i] = v;
		pre[v]++;
	}

	queue<pii> q;
	for(int i = 1; i <= n; i++)
		if(!pre[i])
			q.push({i, 1});
	
	while(!q.empty()) {
		// cout << LEN(q) << '\n';
		int v = q.back().x;
		int pf = q.back().y;
		q.pop();
		
		if(maxi_prof[v] == 0)
			maxi_prof[v] = pf;
		if(adj[v])
			q.push({adj[v], pf+1});
	}
	for(int i = 1; i <= n; i++)
		st.insert({pre[i], {maxi_prof[i], i}});

	map<int, int> mp;
	for(int ans = 1;; ans++) {
		
		for(int i = 0; LEN(st) and st.begin()->x == 0 and i < k; i++) {
			int v = st.begin()->y.y;
			st.erase(st.begin());
			int u = adj[v];
			if(u == 0) continue;
			if(mp.count(u))
				mp[u]++;
			else
				mp[u] = 1;
			pre[u]--;
		}
		if(LEN(st) == 0) {
			cout << ans << '\n';
			exit(0);
		}
		for(auto p : mp) {
			int v = p.x;
			st.erase({pre[p.x]+p.y, {maxi_prof[v], v}});
			st.insert({pre[v], {maxi_prof[v], v}});
		}
		mp.clear();
	}

	return 0;
}
