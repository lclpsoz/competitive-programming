#include "bits/stdc++.h"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/pb_ds/assoc_container.hpp"
using namespace std;
////////////// Prewritten code follows. Look down for solution. ////////////////
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

vector<vi> min_dists (int n, int st_x, int st_y, vector<vector<char>> &mat) {
	// cerr << "st_coord = " << st_x << ' ' << st_y << '\n';
	vector<vi> dist(n+1, vi(n+1, INF<int>));
	vector<pair<pii, int>> bfs;
	bfs.push_back({{st_x, st_y}, 0});
	for (int i = 0; i < LEN(bfs); i++) {
		// cerr << "i = " << i << '\n';
		auto [xy, d] = bfs[i];
		auto &[x, y] = xy;
		if (dist[x][y] != INF<int>) continue;
		dist[x][y] = d;
		auto mov = [&] (int a, int b, int d_nxt) {
			// cerr << "  mov: " << a << ", " << b << ", " << d_nxt << '\n';
			if (a >= 1 and b >= 1 and a <= n and b <= n and
				mat[a][b] != '#' and dist[a][b] == INF<int>)
				bfs.push_back({{a, b}, d_nxt});
			// cerr << "after mov\n";
		};
		mov(x+1, y, d+1);
		// cerr << "here!\n";
		mov(x-1, y, d+1);
		// cerr << "here!\n";
		mov(x, y+1, d+1);
		mov(x, y-1, d+1);
	}

	return dist;
}

bool check (vector<vi> &dists, vpii &players, vpii &portals, int max_d) {
	int n = LEN(players);
	int m = LEN(portals);
	dinic<int> g(n+m+2);
	int tap = n+m;
	int sink = tap+1;
	for (int i = 0; i < n; i++)
		g.add_edge(tap, i, 1);
	for (int i = n; i < n+m; i++)
		g.add_edge(i, sink, 1);
	// cerr << "max_d = " << max_d << '\n';
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (dists[i][j] <= max_d) {
				// cerr << "\t" << i << " -> " << j << '\n';
				g.add_edge(i, n+j, 1);
			}
	return g.max_flow(tap, sink) == n;
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int t;
	cin >> t;
	while (t--) {
		int n, n_players;
		cin >> n >> n_players;
		vector<vector<char>> mat(n+1, vector<char>(n+1));
		vpii portals, players;
		for (int i = 1; i <= n; i++) {
			string s;
			cin >> s;
			for (int j = 1; j <= n; j++) {
				mat[i][j] = s[j-1];
				if (mat[i][j] == 'X')
					portals.push_back({i, j});
				else if (mat[i][j] == 'G')
					players.push_back({i, j});
			}
		}

        assert(LEN(portals) == n_players);

		if (LEN(portals) < n_players)
			cout << "-1\n";
		else {
			vector<vi> dists(LEN(players), vi(LEN(portals)));
			for (int i = 0; i < LEN(players); i++) {
				auto [x, y] = players[i];
				vector<vi> dist = min_dists(n, x, y, mat);
				for (int j = 0; j < LEN(portals); j++) {
					auto [x, y] = portals[j];
					dists[i][j] = dist[x][y];
				}
			}
			
			const int MAXV = n*n + 10;
			int l = 1, r = MAXV;
			while (l < r) {
				int md = (l+r)/2;
				if (check(dists, players, portals, md))
					r = md;
				else
					l = md+1;
			}
			if (r == MAXV)
				cout << "-1\n";
			else
				cout << r << '\n';
		}
	}

	return 0;
}
