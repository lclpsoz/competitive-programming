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

vector<vi> ans;
bool mat[105][105];

void apply_last() {
	vi &last = ans.back();
	for(int i = 0; i < 6; i+=2)
		mat[last[i]][last[i+1]] = !mat[last[i]][last[i+1]];
}

void two(int x, int y) {
	if(mat[x][y]+mat[x+1][y] == 1) {
		if(mat[x][y])
			ans.push_back({x, y, x, y+1, x+1, y+1});
		else
			ans.push_back({x+1, y, x, y+1, x+1, y+1});
		apply_last();
	}
	else if(mat[x][y]+mat[x+1][y] == 2) {
		if(mat[x][y+1])
			ans.push_back({x, y, x+1, y, x, y+1});
		else
			ans.push_back({x, y, x+1, y, x+1, y+1});
		apply_last();
	}
}

int sum4(int x, int y) {
	int ret = 0;
	for(int i = x; i <= x+1; i++)
		for(int j = y; j <= y+1; j++)
			ret += mat[i][j];
	return ret;
}

void four(int x, int y) {
	// cout << "    sum4(x, y) = " << sum4(x, y) << '\n';
	if(sum4(x, y) == 4) {
		ans.push_back({x, y, x, y+1, x+1, y});
		apply_last();
	}

	// cout << "    sum4(x, y) = " << sum4(x, y) << '\n';
	if(sum4(x, y) == 1) {
		if(mat[x][y])
			ans.push_back({x, y, x+1, y, x+1, y+1});
		else
			ans.push_back({x, y+1, x+1, y, x+1, y+1});
		apply_last();
	}

	// cout << "    sum4(x, y) = " << sum4(x, y) << '\n';
	if(sum4(x, y) == 2) {
		vi vals;
		for(int i = x; i <= x+1; i++)
			for(int j = y; j <= y+1; j++)
				if(!mat[i][j]) {
					vals.push_back(i);
					vals.push_back(j);
				}
		for(int i = x; LEN(vals) == 4 and i <= x+1; i++)
			for(int j = y; LEN(vals) == 4 and j <= y+1; j++)
				if(mat[i][j]) {
					vals.push_back(i);
					vals.push_back(j);
				}
		ans.push_back(vals);
		apply_last();
	}

	// cout << "    sum4(x, y) = " << sum4(x, y) << '\n';
	if(sum4(x, y) == 3) {
		vi vals;
		for(int i = x; i <= x+1; i++)
			for(int j = y; j <= y+1; j++)
				if(mat[i][j]) {
					vals.push_back(i);
					vals.push_back(j);
				}
		ans.push_back(vals);
		apply_last();
	}
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int t;
	int n, m;

	cin >> t;
	while(t--) {
		cin >> n >> m;
		for(int i = 1; i <= n; i++) {
			string s;
			cin >> s;
			for(int j = 1; j <= m; j++) {
				mat[i][j] = s[j-1]=='1';
				// cout << "  |" << i << ", " << j << " -> " << mat[i][j] << '\n';
			}
		}

		for(int i = 1; i < n; i++)
			for(int j = 1; j < m; j++)
				if(sum4(i, j) == 3)
					four(i, j);

		for(int i = 1; i < n; i+=2) {
			for(int j = 1; j < m-1; j++)
				two(i, j);
			// cout << "  LEN(ans) = " << LEN(ans) << '\n';
			// cout << "    sum4 = " << sum4(i, m-1) << '\n';
			four(i, m-1);
		}
		if(n%2 == 1) {
			assert(LEN(ans) <= ((n-1)*m));
			for(int j = 1; j < m-1; j++)
				two(n-1, j);
			four(n-1, m-1);
		}
		cout << LEN(ans) << '\n';
		for(vi &vec : ans) {
			cout << vec[0];
			for(int i = 1; i < 6; i++)
				cout << ' ' << vec[i];
			cout << '\n';
		}
		// cout.flush();
		assert(LEN(ans) <= n*m);
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				// cout << mat[i][j];
				// cout.flush();
				assert(!mat[i][j]);
			}
			// cout << '\n';
		}
		ans.clear();
	}

	return 0;
}
