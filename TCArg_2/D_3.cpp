#include "bits/stdc++.h"
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
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

const int N = 110;
double dp[N][N][N];
bool vis[N][N][N];

int solve(int r, int s, int p) {
	double &ret = dp[r][s][p];
	if(vis[r][s][p]) return ret;
	vis[r][s][p] = 1;
	double wr = (r*s);
	double ws = (s*p);
	double wp = (p*r);
	double total = wr+ws+wp;
	ret = solve()
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int r, s, p;
	cin >> r >> s >> p;

	dp[r][s][p] = 1;

	
	double a = 0, b = 0, c = 0;
	for(int i = r; i > 0; i--)
		a += dp[i][0][0];
	for(int j = s; j > 0; j--)
		b += dp[0][j][0];
	for(int k = p; k > 0; k--)
		c += dp[0][0][k];
	double t = a + b + c;
	// double t = 1;
	cout << fixed << a / t << " " << b / t << " " << c / t << endl;

	return 0;
}
