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

template<class flow_t = int>
class dinic
{
private:
    struct edge
    {
        int to;
        flow_t cap, flow = 0;
        edge(int u, flow_t c) : to(u), cap(c) {}
    };

    vector<edge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;
    flow_t flow_inf;

    bool bfs()
    {
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        q.push(s);
        
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (int id : adj[v])
            {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].to] != -1)
                    continue;
                level[edges[id].to] = level[v] + 1;
                q.push(edges[id].to);
            }
        }
        return level[t] != -1;
    }

    flow_t dfs(int v, flow_t pushed)
    {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++)
        {
            int id = adj[v][cid];
            int u = edges[id].to;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            flow_t tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }
    
public:
    dinic(int _n, flow_t inf = 1e9)
    {
        flow_inf = inf;
        n = _n;
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    int add_edge(int from, int to, flow_t cap)
    {
        if(from == to) return -1;
        edges.emplace_back(to, cap);
        edges.emplace_back(from, 0);
        adj[from].push_back(m);
        adj[to].push_back(m + 1);
        m += 2;
        return m - 2;
    }

    void reset_flow()
    {
        for(edge& e : edges)
            e.flow = 0;
    }

    flow_t max_flow(int src, int sink)
    {
        s = src, t = sink;
        flow_t f = 0;
        while (bfs())
        {
            fill(ptr.begin(), ptr.end(), 0);
            while (flow_t pushed = dfs(s, flow_inf))
                f += pushed;
        }
        return f;
    }

    vector<bool> min_cut()
    {
        vector<bool> ans(n, false);
        for(int i = 0; i < n; i++)
            ans[i] = (level[i] != -1);
        return ans;
    }

    int get(int id)
    {
        if(id == -1) return 0;
        return edges[id].flow;
    }
};

// dinic<int> g(n);
// g.add_edge(a, b, cap)
// g.max_flow(source, sink)

vector<char> carrers[30];

int main () {
	 ios_base::sync_with_stdio(false);
     cin.tie(NULL);
    // cout.precision(10);
    int n;
    cin >> n;

    int m = n + 26 + 2;
    int source = m-2;
    int sink = m-1;
    dinic<int> g(m);

    int frstTeam = 'Z'-'A'+1;
    for (int t = frstTeam; t < frstTeam+n; t++) {
        g.add_edge(t, sink, 1);
        string c;
        map<int, int> mp;
        int big = -1;
        for (int i = 0; i < 3; i++) {
            cin >> c;
            for (int j = 0; j < c.size(); j++) {
                mp[c[j] - 'A']++;
                big = max(big, mp[c[j] - 'A']);
            }
        }
        for (int i = 0; i <= 'Z'-'A'; i++) {
            if (mp[i] == big)
                carrers[i].push_back(t);
        }
    }
    int k;
    cin >> k;
    // vector<int> qnt(400, k);
    // int ans = 0;

    // cout << 'src = ' << source << '\n';
    for(int i = 0; i <= 'Z'-'A'; i++) {
        g.add_edge(source, i, k);
        for(int team : carrers[i])
            g.add_edge(i, team, 10000);
    }

    cout <<  g.max_flow(source, sink) << '\n';

    
	return 0;
}
