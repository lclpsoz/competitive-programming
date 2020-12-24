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



int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n, m;
	cin >> n >> m;
	vector<string> mat(n+2);
	string wall = "";
	for (int i = 0; i <= m+1; i++)
		wall.push_back('#');
	mat[0] = wall;
	for (int i = 1; i <= n; i++) {
		cin >> mat[i];
		mat[i] = "#" + mat[i] + "#";
	}
	mat[n+1] = wall;

	vector<vpii> positions(500);

	pii st, en;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (mat[i][j] == 'S')
				st = {i, j};
			else if (mat[i][j] == 'G')
				en = {i, j};
			else if (mat[i][j] != '#' and mat[i][j] != '.') {
				positions[mat[i][j]].push_back({i, j});
			}

	bitset<500> vis_char;
	vector<vi> dist(n+1, vi(m+1, INF<int>));
	vector<pair<pii, int>> bfs;
	bfs.push_back({st, 0});
	auto mov = [&] (int a, int b, int dst) {
		if (mat[a][b] != '#' and !vis_char[mat[a][b]] and dist[a][b] == INF<int>)
			bfs.push_back({{a, b}, dst});
	};
	for (int i = 0; i < LEN(bfs); i++) {
		// cerr << "i = " << i << '\n';
		auto [xy, d] = bfs[i];
		auto [x, y] = xy;
		if (dist[x][y] != INF<int>) continue;
		// cerr << "pos = " << x << ", " << y << " -> " << d << '\n';
		dist[x][y] = d;
		mov(x+1, y, d+1);
		mov(x-1, y, d+1);
		mov(x, y+1, d+1);
		mov(x, y-1, d+1);
		if (mat[x][y] >= 'a' and mat[x][y] <= 'z' and !vis_char[mat[x][y]]) {
			for (auto p : positions[mat[x][y]])
				bfs.push_back({p, d+1});
			vis_char[mat[x][y]] = 1;
		}
	}
	int ans = dist[en.x][en.y];
	cout << (ans == INF<int> ? -1 : ans) << '\n';

	return 0;
}
