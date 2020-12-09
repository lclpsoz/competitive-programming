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
ll dist[N];
bitset<N> critical;

void no () {
    cout << "-1\n";
    exit(0);
}

int main () {
	// freopen("hide.in", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> dist[i];
        critical[i] = 1;
    }

    vi min_edge(n+1, INF<int>);
    vi cnt_valid(n+1);
    int cnt_critical = n;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        min_edge[u] = min(min_edge[u], w);
        min_edge[v] = min(min_edge[v], w);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        if (dist[u]+w < dist[v] or dist[v]+w < dist[u])
            no();
        else if (critical[v] and dist[u]+w == dist[v])
            critical[v] = 0, cnt_critical--;
        else if (critical[u] and dist[v]+w == dist[u])
            critical[u] = 0, cnt_critical--;
        
        if (dist[u] > w)
            cnt_valid[v] = -INF<int>;
        if (dist[v] > w)
            cnt_valid[u] = -INF<int>;
    }

    for (int v = 1; v <= n; v++)
        if (critical[v])
            for (auto [u, w] : adj[v])
                if (w == dist[v])
                    cnt_valid[u]++;

    for (int i = 1; i <= n; i++)
        if (dist[i] == min_edge[i]*2 and cnt_valid[i] == cnt_critical-critical[i]) {
            cout << i << '\n';
            exit(0);
        }
    no();

	return 0;
}
