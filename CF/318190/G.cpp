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

using matrix = vector<vi>;

matrix read_matrix (int n, int m) {
	matrix ret(n, vi(m));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
			ret[i][j] = (s[j]=='1');
	}

	return ret;
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int k, n, m;
	cin >> k >> n >> m;

	vector<pair<matrix, int>> vec;
	for (int i = 1; i <= k; i++)
		vec.push_back({read_matrix(n, m), i});

	sort(ALL(vec), [&](pair<matrix, int> &_lhs, pair<matrix, int> &_rhs) {
		matrix &lhs = _lhs.x;
		matrix &rhs = _rhs.x;
		bool l, r;
		l = r = false;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (lhs[i][j] and !rhs[i][j]) l = true;
				else if (!lhs[i][j] and rhs[i][j]) r = true;
			}
		if (l and r) {
			cout << "IMPOSSIBLE\n";
			exit(0);
		}
		return l;
	});

	// for (int i = 0; i < n; i++)
	// 	for (int j = 0; j < m; j++)
	// 		cerr << vec[0].x[i][j] << " \n"[j==m-1];

	matrix ans_mat(n, vi(m));
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++)
			for (int l = 0; l < m; l++)
				if (vec[i].x[j][l])
					ans_mat[j][l] = i+1;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cout << ans_mat[i][j] << " \n"[j==m-1];

	vi ans_t(k+1);
	for (int i = 0; i < k; i++)
		ans_t[vec[i].y] = i+1;

	for (int i = 1; i <= k; i++)
		cout << ans_t[i] << " \n"[i==k];

	return 0;
}
