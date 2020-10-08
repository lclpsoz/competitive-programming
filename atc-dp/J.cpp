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

const ld EPS = 1e-16;
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

int n;
bitset<301> vis[301][301];
double dp[301][301][301];
double val[301];

double solve(int v1, int v2, int v3) {
	int sum = v1+v2+v3;
	if(sum == 0) return 0;
	double &ret = dp[v1][v2][v3];
	if(vis[v1][v2][v3] != 0) return ret;
	vis[v1][v2][v3] = 1;
	// cout << v1 << ' ' << v2 << ' ' << v3 << '\n';
	ret = val[n-sum];
	int amnt = 0;
	double part_sum = 0;
	if(v1)
		part_sum += v1*solve(v1-1, v2, v3);
	if(v2)
		part_sum += v2*solve(v1+1, v2-1, v3);
	if(v3)
		part_sum += v3*solve(v1, v2+1, v3-1);
	return ret += part_sum/sum;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(15);

	vi amounts(4);
	cin >> n;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		amounts[x]++;
	}

	for(int i = 0; i <= n; i++) {
		double &now = val[i];
		double prob_win = (double)(n-i)/n;
		double prob = prob_win;
		for(int j = 1; prob > EPS; j++) {
			now += prob*j;
			prob *= (1-prob_win);
		}
		// cout << "val of " << i << " = " << val[i] << '\n';
	}

	cout << solve(amounts[1], amounts[2], amounts[3]) << '\n';

	return 0;
}
