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

const int N = 2e5 + 100;
const int INF= 1e9;

int n, c;
int a[N], b[N];
int dist[N][2];
set<pair<int, pair<int, int>>> st;

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);
	scanf("%d %d", &n, &c);
	for(int i = 1; i < n; i++)
		scanf("%d", &a[i]), dist[i][0] = INF, dist[i][1] = INF;
	dist[n][0] = dist[n][1] = INF;
	for(int i = 1; i < n; i++)
		scanf("%d", &b[i]);

	// dist[1][0] = dist[1][1] = 0;
	st.insert({0, {0, 1}});
	while(!st.empty()) {
		auto p = *st.begin();
		st.erase(st.begin());
		int d = p.x;
		int elev = p.y.x;
		int v = p.y.y;
		if(dist[v][elev] != INF) continue;
		// printf("v = %d, %d; d = %d\n", v, elev, d);
		dist[v][elev] = d;
		if(elev)
			st.insert({d+b[v], {1, v+1}});
		else
			st.insert({d+b[v] + c, {1, v+1}});
		// printf("%d %d %d\n", d, a[v], b[v]);
		st.insert({d+a[v], {0, v+1}});
		// printf("  st:\n");
		// for(auto pp : st)
		// 	printf("    d = %d elev = %d v = %d\n", pp.x, pp.y.x, pp.y.y);
	}

	for(int i = 1; i <= n; i++)
		printf("%d%c", min(dist[i][0], dist[i][1]), " \n"[i==n]);

	return 0;
}
