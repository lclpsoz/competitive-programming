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
	mt.assign(n_portals, -1);
    for (int i = 0; i < n_players; i++) {
        vis.assign(n_players, false);
        try_kuhn(i, adj, vis, mt, max_w);
    }

    for (int i = 0; i < n_portals; i++)
        if (mt[i] == -1)
            return false;
    return true;
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
