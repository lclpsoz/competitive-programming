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

using board = vector<string>;

map<pair<board, bool>, int> dp;

int eval (board &mat) {
	int ret = 0;
	// for (int i = 0; i < 3; i++)
	// 	cerr << mat[i] << '\n';
	for (int i = 0; i < 3; i++) {
		if (mat[i][0] == mat[i][1] and mat[i][0] == mat[i][2])
			ret += (mat[i][0] == 'X' ? -1 : 1);
		if (mat[0][i] == mat[1][i] and mat[0][i] == mat[2][i])
			ret += (mat[0][i] == 'X' ? -1 : 1);
	}
	// cerr << "eval_1 = " << ret << '\n';
	if (mat[0][0] == mat[1][1] and mat[0][0] == mat[2][2]) {
		ret += (mat[0][0] == 'X' ? -1 : 1);
		// cerr << "here!\n";
	}
	if (mat[0][2] == mat[1][1] and mat[0][2] == mat[2][0]) {
		ret += (mat[0][2] == 'X' ? -1 : 1);
		// cerr << "here!\n";
	}
	// cerr << "player = " << player << '\n';
	// cerr << "  eval = " << ret << '\n';
	return ret;
}

bool free_spot (board &mat) {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (mat[i][j] == '.')
				return true;
	return false;
}

int solve (board mat, bool player) {
	if (dp.count({mat, player})) return dp[{mat, player}];
	int &ret = dp[{mat, player}];


	if (!free_spot(mat)) return ret = eval(mat);
	if (player == 1) {
		ret = -INF<int>;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (mat[i][j] == '.') {
					mat[i][j] = 'O';
					ret = max(ret, solve(mat, 0));
					mat[i][j] = '.';
				}
	}
	else {
		ret = INF<int>;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (mat[i][j] == '.') {
					mat[i][j] = 'X';
					ret = min(ret, solve(mat, 1));
					mat[i][j] = '.';
				}
	}
	return ret;
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
		int player;
		cin >> player;
		board mat;
		for (int i = 0; i < 3; i++) {
			string s;
			cin >> s;
			mat.push_back(s);
		}
		cout << solve(mat, player) << '\n';
		// cerr << "LEN(dp) = " << LEN(dp) << '\n';
	}

	return 0;
}
