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

#define NIL 0

// A class to represent Bipartite graph for Hopcroft
// Karp implementation
class BipGraph
{
    // m and n are number of vertices on left
    // and right sides of Bipartite Graph
    int m, n;
 
    // adj[u] stores adjacents of left side
    // vertex 'u'. The value of u ranges from 1 to m.
    // 0 is used for dummy vertex
    list<int> *adj;
 
    // These are basically pointers to arrays needed
    // for hopcroftKarp()
    int *pairU, *pairV, *dist;
 
public:
    BipGraph(int m, int n); // Constructor
    void addEdge(int u, int v); // To add edge
 
    // Returns true if there is an augmenting path
    bool bfs();
 
    // Adds augmenting path if there is one beginning
    // with u
    bool dfs(int u);
 
    // Returns size of maximum matcing
    int hopcroftKarp();
};
 
// Returns size of maximum matching
int BipGraph::hopcroftKarp()
{
    // pairU[u] stores pair of u in matching where u
    // is a vertex on left side of Bipartite Graph.
    // If u doesn't have any pair, then pairU[u] is NIL
    pairU = new int[m+1];
 
    // pairV[v] stores pair of v in matching. If v
    // doesn't have any pair, then pairU[v] is NIL
    pairV = new int[n+1];
 
    // dist[u] stores distance of left side vertices
    // dist[u] is one more than dist[u'] if u is next
    // to u'in augmenting path
    dist = new int[m+1];
 
    // Initialize NIL as pair of all vertices
    for (int u=0; u<=m; u++)
        pairU[u] = NIL;
    for (int v=0; v<=n; v++)
        pairV[v] = NIL;
 
    // Initialize result
    int result = 0;
 
    // Keep updating the result while there is an
    // augmenting path.
    while (bfs())
    {
        // Find a free vertex
        for (int u=1; u<=m; u++)
 
            // If current vertex is free and there is
            // an augmenting path from current vertex
            if (pairU[u]==NIL && dfs(u))
                result++;
    }
    return result;
}
 
// Returns true if there is an augmenting path, else returns
// false
bool BipGraph::bfs()
{
    queue<int> Q; //an integer queue
 
    // First layer of vertices (set distance as 0)
    for (int u=1; u<=m; u++)
    {
        // If this is a free vertex, add it to queue
        if (pairU[u]==NIL)
        {
            // u is not matched
            dist[u] = 0;
            Q.push(u);
        }
 
        // Else set distance as infinite so that this vertex
        // is considered next time
        else dist[u] = INF<int>;
    }
 
    // Initialize distance to NIL as infinite
    dist[NIL] = INF<int>;
 
    // Q is going to contain vertices of left side only. 
    while (!Q.empty())
    {
        // Dequeue a vertex
        int u = Q.front();
        Q.pop();
 
        // If this node is not NIL and can provide a shorter path to NIL
        if (dist[u] < dist[NIL])
        {
            // Get all adjacent vertices of the dequeued vertex u
            list<int>::iterator i;
            for (i=adj[u].begin(); i!=adj[u].end(); ++i)
            {
                int v = *i;
 
                // If pair of v is not considered so far
                // (v, pairV[V]) is not yet explored edge.
                if (dist[pairV[v]] == INF<int>)
                {
                    // Consider the pair and add it to queue
                    dist[pairV[v]] = dist[u] + 1;
                    Q.push(pairV[v]);
                }
            }
        }
    }
 
    // If we could come back to NIL using alternating path of distinct
    // vertices then there is an augmenting path
    return (dist[NIL] != INF<int>);
}
 
// Returns true if there is an augmenting path beginning with free vertex u
bool BipGraph::dfs(int u)
{
    if (u != NIL)
    {
        list<int>::iterator i;
        for (i=adj[u].begin(); i!=adj[u].end(); ++i)
        {
            // Adjacent to u
            int v = *i;
 
            // Follow the distances set by BFS
            if (dist[pairV[v]] == dist[u]+1)
            {
                // If dfs for pair of v also returns
                // true
                if (dfs(pairV[v]) == true)
                {
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
            }
        }
 
        // If there is no augmenting path beginning with u.
        dist[u] = INF<int>;
        return false;
    }
    return true;
}
 
// Constructor
BipGraph::BipGraph(int m, int n)
{
    this->m = m;
    this->n = n;
    adj = new list<int>[m+1];
}
 
// To add edge from u to v and v to u
void BipGraph::addEdge(int u, int v)
{
    adj[u].push_back(v); // Add u to v’s list.
}

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

bool try_kuhn (int v, vector<vector<pii>> &adj, vector<bool> &vis, vi &mt, int max_w) {
    if (vis[v])
        return false;
    vis[v] = 1;
    for (auto [u, w] : adj[v])
        if (w <= max_w and (mt[u] == -1 or try_kuhn(mt[u], adj, vis, mt, max_w))) {
            mt[u] = v;
            return true;
        }
    return false;
}

bool check (vector<vector<pii>> &adj, vector<bool> &vis,
            vi &mt, int max_w, int n_players, int n_portals) {
	BipGraph g(n_players, n_portals);
	for (int i = 0; i < n_players; i++)
		for (auto [j, w] : adj[i])
			if (w <= max_w)
				g.addEdge(i+1, j+1);
	return g.hopcroftKarp() == n_players;
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
			
            int n_players = LEN(players);
            int n_portals = LEN(portals);

            vi mt(n_portals);
            vector<bool> vis(n_players);
            vector<vpii> adj(n_players); 

            for (int i = 0; i < n_players; i++)
                for (int j = 0; j < n_portals; j++)
                    adj[i].push_back({j, dists[i][j]});

			const int MAXV = n*n + 10;
			int l = 1, r = MAXV;
			while (l < r) {
				int md = (l+r)/2;
				if (check(adj, vis, mt, md, n_players, n_portals))
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
