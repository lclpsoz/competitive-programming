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

inline int fcmp (ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod (ll x, int m = MOD) {
	int ret = (int)x%m;
	if (ret < 0)
		ret += m;
	return ret;
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

int shortest (int n, int m, vector<vector<char>> &mat) {
	if (mat[1][1] == '#') return INF<int>;
	vector<pair<pii, int>> bfs = {{{1, 1}, 0}};
	vector<vi> dist(505, vi(505, INF<int>));
	for (int i = 0; i < LEN(bfs); i++) {
		auto [xy, d] = bfs[i];
		auto [x, y] = xy;

		if (dist[x][y] != INF<int>) continue;
		dist[x][y] = d;

		if (mat[x][y+1] == '.' and dist[x][y+1] == INF<int>)
			bfs.push_back({{x, y+1}, d+1});
		if (mat[x][y-1] == '.' and dist[x][y-1] == INF<int>)
			bfs.push_back({{x, y-1}, d+1});

		if (mat[x+1][y] == '.' and dist[x+1][y] == INF<int>)
			bfs.push_back({{x+1, y}, d+1});
		if (mat[x-1][y] == '.' and dist[x-1][y] == INF<int>)
			bfs.push_back({{x-1, y}, d+1});
	}
	return dist[n][m];
}

int shortest_both (int n, int m, vector<vector<char>> &mat1, vector<vector<char>> &mat2) {
	if (mat1[1][1] == '#' or mat2[1][1] == '#') return INF<int>;
	vector<pair<pii, int>> bfs = {{{1, 1}, 0}};
	vector<vi> dist(505, vi(505, INF<int>));
	for (int i = 0; i < LEN(bfs); i++) {
		auto [xy, d] = bfs[i];
		auto [x, y] = xy;

		if (dist[x][y] != INF<int>) continue;
		dist[x][y] = d;

		if (mat1[x][y+1] == '.' and mat2[x][y+1] == '.' and dist[x][y+1] == INF<int>)
			bfs.push_back({{x, y+1}, d+1});
		if (mat1[x][y-1] == '.' and mat2[x][y-1] == '.' and dist[x][y-1] == INF<int>)
			bfs.push_back({{x, y-1}, d+1});

		if (mat1[x+1][y] == '.' and mat2[x+1][y] == '.' and dist[x+1][y] == INF<int>)
			bfs.push_back({{x+1, y}, d+1});
		if (mat1[x-1][y] == '.' and mat2[x-1][y] == '.' and dist[x-1][y] == INF<int>)
			bfs.push_back({{x-1, y}, d+1});
	}
	return dist[n][m];
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n, m;
	cin >> n >> m;
	vector<vector<char>> mat1(n+2, vector<char>(m+2, '#')), mat2(n+2, vector<char>(m+2, '#'));
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++)
			mat1[i][j] = s[j-1];
	}
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++)
			mat2[i][j] = s[j-1];
	}

	int a = shortest(n, m, mat1);
	int b = shortest(n, m, mat2);
	if (a < n*m and a == b)
		cout << (a == shortest_both(n, m, mat1, mat2) ? "YES" : "NO") << '\n';
	else
		cout << "NO\n";

	return 0;
}
