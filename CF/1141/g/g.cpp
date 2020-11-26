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

const int N = 2e5 + 10;

vpii adj[N];
int ans[N];
bitset<N> fr;

void solve(int v, int p, int bef) {
	int nxt = 1 + (!fr[v] and bef==1);
	for(auto &[u, e] : adj[v])
		if(u != p) {
			ans[e] = nxt;
			solve(u, v, nxt);
			if(!fr[v]) {
				nxt++;
				nxt+=bef==nxt;
			}
		}
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n, k;
	cin >> n >> k;
	for(int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back({y, i});
		adj[y].push_back({x, i});
	}
	vpii vec;
	for(int i = 1; i <= n; i++)
		vec.push_back({LEN(adj[i]), i});
	sort(ALL(vec));
	reverse(ALL(vec));
	for(int i = 0; i < k; i++)
		fr[vec[i].y] = 1;
	cout << vec[k].x << '\n';
	solve(vec[0].y, vec[0].y, -1);
	for(int i = 1; i < n; i++)
		cout << ans[i] << " \n"[i==n-1];

	return 0;
}
