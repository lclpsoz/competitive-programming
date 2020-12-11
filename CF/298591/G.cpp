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

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e3 + 10;

int n, m;
int dp_normal[N][42][2], dp_inp[N][42][2];
vpii normal, inp;

int solve(int p, int pw, int active, vpii &vals, int dp[N][42][2]) {
	if(p == LEN(vals)) return 0;
	int &ret = dp[p][pw][active];
	if(ret != -1) return ret;
	if(active and pw == 0) active = 0;
	ret = 0;
	if(active) {
		ret = max(ret, solve(p+1, pw-1, active, vals, dp)+vals[p].x*2);
	} else if(vals[p].y) {
		ret = max(ret, solve(p+1, min(40, pw+10), 0, vals, dp)+vals[p].x);
	} else if(pw) {
		ret = max(ret, solve(p+1, pw-1, active, vals, dp)+vals[p].x*2);
	}
	return ret;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	memset(dp_normal, -1, sizeof dp_inp);
	memset(dp_inp, -1, sizeof dp_inp);

	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x *= 50;
		normal.push_back({x, y});
	}
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x *= 50;
		inp.push_back({x, y});
	}

	// for(int i = 0; i < n; i++)
		for(int j = 0; j <= 40; j++)
			for(int k = 0; k < 2; k++)
				solve(0, j, 0, normal, dp_normal);
	// for(int i = 0; i < m; i++)
		for(int j = 0; j <= 40; j++)
			for(int k = 0; k < 2; k++)
				solve(0, j, 0, inp, dp_inp);

	if(m == 0)
		cout << dp_normal[0][0][0] << '\n';
	else {
		int ans = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j <= 40; j++)
				for(int j2 = 40-j; j2 >= 0; j2--)
					for(int k = 0; k < 2; k++)
						if(dp[i][j][k] != -1 and dp[0][)
	}




	return 0;
}
