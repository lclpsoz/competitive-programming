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

const int N = 1e5 + 10;
int n, a[N];
bool dp[N][3][2], vis[N][3][2];
int v[N][2];

bool solve(int i, int j, bool k) {
	if(i == n - 1) {
		return j == 2;
	}

	bool& ans = dp[i][j][k];

	if(!vis[i][j][k]) {
		vis[i][j][k] = true;
		
		if(j == 0) {
			if(a[i] == -1) {
				if(a[i + 1] == -1) {
					ans = ans || solve(i + 1, 0, k) || solve(i + 1, 1, k);
					if(!k && v[i + 1][1] >= v[i][k])
						ans = ans || solve(i + 1, 0, 1) || solve(i + 1, 1, 1);
				}
				else {
					if(a[i + 1] >= v[i][k])
					 	ans = ans || solve(i + 1, 0, 0) || solve(i + 1, 1, 0);
				}
			}
			else {
				if(a[i + 1] == -1) {
					ans = ans || solve(i + 1, 0, 0) || solve(i + 1, 1, 0);
					if(v[i + 1][1] >= a[i])
						ans = ans || solve(i + 1, 0, 1) || solve(i + 1, 1, 1);
				}
				else {
					if(a[i + 1] >= a[i])
					 	ans = ans || solve(i + 1, 0, 0) || solve(i + 1, 1, 0);
				}
			}
		}
		else if(j == 1) {
			if(a[i] == -1) {
				if(a[i + 1] == -1) {
					ans = ans || solve(i + 1, 2, k);
					if(!k && v[i + 1][1] <= v[i][0])
						ans = ans || solve(i + 1, 2, 1);
				}
				else {
					if(a[i + 1] <= v[i][k])
						ans = ans || solve(i + 1, 2, 0);
				}
			}
			else {
				if(a[i + 1] == -1) {
					ans = ans || solve(i + 1, 2, 0);
					if(v[i + 1][1] <= a[i])
						ans = ans || solve(i + 1, 2, 1);
				}
				else {
					if(a[i + 1] <= a[i])
						ans = ans || solve(i + 1, 2, 0);
				}
			}
		}
		else {
			if(a[i] == -1) {
				if(a[i + 1] == -1) {
					ans = ans || solve(i + 1, 2, k) || solve(i + 1, 0, k);
					if(!k && v[i + 1][1] <= v[i][0])
						ans = ans || solve(i + 1, 2, 1) || solve(i + 1, 0, 1);
					if(!k && v[i + 1][1] >= v[i][0])
						ans = ans || solve(i + 1, 0, 1);
				}
				else {
					if(a[i + 1] <= v[i][k])
						ans = ans || solve(i + 1, 2, 0) || solve(i + 1, 0, 0);
					if(a[i + 1] >= v[i][k])
						ans = ans || solve(i + 1, 0, 0);
				}
			}
			else {
				if(a[i + 1] == -1) {
					ans = ans || solve(i + 1, 2, 0) || solve(i + 1, 0, 0);
					if(v[i + 1][1] <= a[i])
						ans = ans || solve(i + 1, 2, 1) || solve(i + 1, 0, 1);
					if(v[i + 1][1] >= a[i])
						ans = ans || solve(i + 1, 0, 1);
				}
				else {
					if(a[i + 1] <= a[i])
						ans = ans || solve(i + 1, 2, 0) || solve(i + 1, 0, 0);
					if(a[i + 1] >= a[i])
						ans = ans || solve(i + 1, 0, 0);
				}
			}
		}
	}

	return ans;
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for(int i = 0; i < n; i++) {
		if(a[i] == -1) {
			if(!i) v[i][0] = 1;
			else if(a[i - 1] == -1) v[i][0] = v[i - 1][0];
			else v[i][0] = a[i - 1];
		}
	}

	for(int i = n - 1; i >= 0; i--) {
		if(a[i] == -1) {
			if(i == n - 1) v[i][1] = 1;
			else if(a[i + 1] == -1) v[i][1] = v[i + 1][1];
			else v[i][1] = a[i + 1];
		}
	}

	cout << (solve(0, 0, 0) ? "Y" : "N") << endl;

	return 0;
}
