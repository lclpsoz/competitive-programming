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

int t;

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> t;
	while(t--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<vi> adj(n+5);
		vector<int> cnt_e(n+5);
		set<pii> st;
		while(m--) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for(int i = 1; i <= n; i++) {
			cnt_e[i] = LEN(adj[i]);
			st.insert({cnt_e[i], i});
			cout << "  i = " << i << ", cnt_e = " << cnt_e[i] << '\n';
		}

		// Clique
		while(LEN(st) > k or st.begin()->x < k-1) {
			int q, v;
			q = st.begin()->x;
			v = st.begin()->y;
			cout << "v = " << v << ", q = " << q << '\n';
			cout.flush();
			st.erase(st.begin());
			cnt_e[v] = 0;
			for(int u : adj[v])
				if(cnt_e[u]) {
					st.erase({cnt_e[u], u});
					cnt_e[u]--;
					st.insert({cnt_e[u], u});
				}
		}
		if(LEN(st) == k)
		if(LEN(st) < k)
			cout << "-1\n";
		else {
			if(LEN(st) != k)
				cout << "1 " << LEN(st) << '\n';
			else
				cout << "2\n";
			for(auto p :st)
				cout << p.y << ' ';
			cout << '\n';
		}
	}

	return 0;
}
