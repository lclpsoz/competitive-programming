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
vpii adj[N], radj[N];
int n, m, k;
vector<vi> dijkstra(int s, bool rev)
{
    vector<vi> dist(n, vi(k + 1, int(1e9)));
    using node = pair<int, pii>;
    priority_queue<node, vector<node>, greater<node>> pq;
    dist[s][0] = 0;
    pq.push({dist[s][0], {s, 0}});

    while(!empty(pq))
    {
        auto [d, st] = pq.top();
        pq.pop();
        auto [v, q] = st;
        if(dist[v][q] != d)
            continue;
        
        if(rev)
        {
            for(auto [u, w] : radj[v])
                if(dist[u][q] > d + w)
                {
                    dist[u][q] = d + w;
                    pq.push({dist[u][q], {u, q}});
                }

            for(auto [u, w] : radj[v])
                if(q < k && dist[u][q + 1] > d)
                {
                    dist[u][q + 1] = d;
                    pq.push({dist[u][q + 1], {u, q + 1}});
                }
        }
        else
        {
            for(auto [u, w] : adj[v])
                if(dist[u][q] > d + w)
                {
                    dist[u][q] = d + w;
                    pq.push({dist[u][q], {u, q}});
                }

            for(auto [u, w] : adj[v])
                if(q < k && dist[u][q + 1] > d)
                {
                    dist[u][q + 1] = d;
                    pq.push({dist[u][q + 1], {u, q + 1}});
                }
        }
    }

    return dist;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

    cin >> n >> m;

    int a, b;
    cin >> a >> b >> k;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        radj[v].push_back({u, w});
    }

    auto da = dijkstra(a, 0);
    auto db = dijkstra(b, 0);
    
    auto dar = dijkstra(a, 1);
    auto dbr = dijkstra(b, 1);

    pii ans(1e9, n);

    for(int v = 0; v < n; v++)
    {
        if(v == a || v == b) continue;
        int ca = 1e9;
        int cb = 1e9;
        for(int i = 0; i <= k; i++)
            for(int j = 0; i + j <= k; j++)
            {
                ca = min(ca, da[v][i] + dar[v][j]);
                cb = min(cb, db[v][i] + dbr[v][j]);
            }

        ans = min(ans, pii(ca + cb, v));
    }

    if(ans.first == int(1e9)) cout << ">:(" << endl;
    else cout << ans.second << " " << ans.first << endl;

	return 0;
}
