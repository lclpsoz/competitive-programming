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
			
			vi perm;
			for (int i = 0; i < LEN(portals); i++)
				perm.push_back(i);
			int ans = INF<int>;
			do {
				int max_dist = -1;
				for (int i = 0; i < n_players; i++)
					max_dist = max(max_dist, dists[i][perm[i]]);
				ans = min(ans, max_dist);
			} while (next_permutation(ALL(perm)));
			if (ans == INF<int>)
				cout << "-1\n";
			else
				cout << ans << '\n';
		}
	}

	return 0;
}
