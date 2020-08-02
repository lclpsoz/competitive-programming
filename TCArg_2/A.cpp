#include "bits/stdc++.h"
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
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

template<typename T>
const T INF = (is_same<T, int>::value ? 1e9 : 1e18);

template<class cost_t, class flow_t>
class MinCostFlow
{
private:
    struct edge
    {
        int to;
        flow_t cap, flow = 0;
        cost_t cost;
        edge(int u, cost_t cc, flow_t c) : to(u), cap(c), cost(cc) {}
    };

    vector<edge> edges;
    vector<vector<int>> adj;
    vector<bool> in_queue;
    vector<cost_t> dist;
    vector<int> prev, id_prev;
    queue<int> q;
    int s, t;
    int n, m = 0;

    pair<cost_t, flow_t> spfa(flow_t k)
    {
        fill(dist.begin(), dist.end(), cost_inf);
        fill(prev.begin(), prev.end(), -1);
        fill(in_queue.begin(), in_queue.end(), false);

        q.push(s);
        dist[s] = 0;
        in_queue[s] = true;
        
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            in_queue[v] = false;

            for (int id : adj[v])
            {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                int u = edges[id].to;
                if(edges[id].cost + dist[v] < dist[u])
                {
                    prev[u] = v;
                    id_prev[u] = id;
                    dist[u] = edges[id].cost + dist[v];

                    if(!in_queue[u])
                    {
                        in_queue[u] = true;
                        q.push(u);
                    }
                }
            }
        }

        flow_t mn = k;

        for(int cur = t; prev[cur] != -1; cur = prev[cur])
        {
            int id = id_prev[cur];
            mn = min(mn, edges[id].cap - edges[id].flow);
        }

        if(prev[t] == -1 || mn == 0) return {0, 0};

        pair<cost_t, flow_t> ans(0, mn);

        for(int cur = t; prev[cur] != -1; cur = prev[cur])
        {
            int id = id_prev[cur];
            edges[id].flow += mn;
            edges[id ^ 1].flow -= mn;
            ans.first += mn * edges[id].cost;
        }

        return ans;
    }    
public:
    const cost_t cost_inf = INF<cost_t>;
    const flow_t flow_inf = INF<flow_t>;

    MinCostFlow(int _n)
    {
        n = _n;
        adj.resize(n);
        dist.resize(n);
        prev.resize(n);
        id_prev.resize(n);
        in_queue.resize(n);
    }

    int add_edge(int from, int to, cost_t cost, flow_t cap)
    {
        if(from == to) return -1;
        edges.emplace_back(to, cost, cap);
        edges.emplace_back(from, -cost, 0);
        adj[from].push_back(m);
        adj[to].push_back(m + 1);
        m += 2;
        return m - 2;
    }

    pair<cost_t, flow_t> min_cost_flow(int src, int sink, flow_t k = 1e9)
    {
        s = src, t = sink;
        
        pair<cost_t, flow_t> ans(0, 0);
        pair<cost_t, flow_t> now;

        while((now = spfa(k - ans.second)).second)
        {
            ans.first += now.first;
            ans.second += now.second;
        }
        return ans;
    }
};

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n, q;
	cin >> n >> q;

	MinCostFlow<int, int> g(2 + n + n);
	int s = n + n, t = n + n + 1;

	vi mn(n, 1), mx(n, n);
	while(q--)
	{
		int tt, l, r, v;
		cin >> tt >> l >> r >> v;
		--l, --r;
		if(tt == 1) for(int i = l; i <= r; i++) mn[i] = max(mn[i], v);
		else for(int i = l; i <= r; i++) mx[i] = min(mx[i], v);
	}

	for(int i = 0; i < n; i++)
	{
		g.add_edge(s, i, 0, 1);
		--mn[i], --mx[i];
		for(int j = mn[i]; j <= mx[i]; j++)
			g.add_edge(i, n + j, 0, 1);
		
		for(int j = 1; j <= n; j++)
			g.add_edge(n + i, t, 2 * j - 1, 1);
	}

	auto [c, f] = g.min_cost_flow(s, t);

	if(f < n) cout << -1 << endl;
	else cout << c << endl;

	return 0;
}
