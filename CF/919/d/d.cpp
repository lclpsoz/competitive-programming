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

const int N = 3e5 + 10;

int t_now = 1;
int tin[N], tlo[N], tout[N];
int freq[40];
vi adj[N];
string s;
int dp[N][40];
int ans;

void no() {
	cout << "-1\n";
	exit(0);
}

void solve(int v) {
	if(tin[v]) return;

	tin[v] = t_now++;
	tlo[v] = tin[v];
	if(LEN(adj[v]) == 0)
		dp[v][s[v]] = 1;
	else
		for(int u : adj[v]) {
			solve(u);
			if(!tout[u])
				tlo[v] = min(tlo[v], tlo[u]);
			for(int i = 0; i < 30; i++)
				dp[v][i] = max(dp[v][i], dp[u][i]+(s[v]==i));
		}
	// cout << "tlo[" << v << "] = " << tlo[v] << ", tin = " << tin[v] << '\n';
	// cout.flush();
	if(tlo[v] < tin[v]) no(); // loop
	for(int i = 0; i < 30; i++)
		ans = max(ans, dp[v][i]);
	tout[v] = t_now++;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n, m;
	cin >> n >> m;
	cin >> s;
	s = '-' + s;
	for(char &c : s) c-='a';

	while(m--) {
		int x, y;
		cin >> x >> y;
		if(x == y) no();
		adj[x].push_back(y);
	}

	for(int i = 1; i <= n; i++)	
		solve(i);
	cout << ans << '\n';


	return 0;
}
