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

const int N = 1e5 + 100;

int n;
int st, en;
vector<int> adj[N];
int taka[N], aoki[N];

void dfsAoki(int v, int p, int t) {
	aoki[v] = t;
	for(int u : adj[v])
		if(u != p)
			dfsAoki(u, v, t+1);
}

void dfsTak(int v, int p, int t) {
	taka[v] = t;
	if(aoki[v] <= t) return;
	for(int u : adj[v])
		if(u != p)
			dfsTak(u, v, t+1);
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
	
	cin >> n;
	if(n == 2) {
		cout << "0\n";
		exit(0);
	}
	cin >> st >> en;
	for(int i = 0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(taka, -1, sizeof taka);
	dfsAoki(en, en, 0);
	dfsTak(st, st, 0);
	int ans = -1e9;
	for(int v = 1; v <= n; v++) {
		if(LEN(adj[v]) == 1 and taka[v] != -1) {
			ans = max(ans, aoki[v]-(aoki[v] != taka[v]));
		}
	}
	cout << ans << '\n';


	return 0;
}
