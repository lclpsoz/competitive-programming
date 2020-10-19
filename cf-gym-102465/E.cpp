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

pii range[10100];
vector<pair<string, int>> vec;

void no() {
	cout << "IMPOSSIBLE\n";
	exit(0);
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(2);

	int p;
	int n = 10000;
	cin >> p;
	
	for(int i = 0; i<=n; i++)
		range[i] = {1e9, -1e9};
	for(int i = 0; i<=n; i++) {
		int v=(i+50)/100;
		// cout << i << ' ' << v << '\n';
		range[v].x = min(range[v].x, i);
		range[v].y = max(range[v].y, i);
	}
	// cout << range[32].x << ' ' << range[32].y << '\n';
	// cout << range[32].x/100.0 << ' ' << range[32].y/100.0 << '\n';
	int sum_max, sum_min;
	sum_max = sum_min = 0;
	for(int i = 0; i < p; i++) {
		string s;
		int val;
		cin >> s >> val;
		vec.push_back({s, val});
		sum_min += range[val].x;
		sum_max += range[val].y;
	}

	vector<pair<int, int>> ans;
	for(int i = 0; i < p; i++) {
		pii range_now = range[vec[i].y];
		int now_max = n-(sum_min-range_now.x);
		int now_min = n-(sum_max-range_now.y);
		if(now_max < range_now.x or now_min > range_now.y)
			no();
		else {
			// cout << i << ": " << range_now.x << ' ' << range_now.y << '\n';
			ans.push_back({max(now_min, range_now.x), min(now_max, range_now.y)});
		}
	}
	for(int i = 0; i < p; i++)
		cout << fixed << vec[i].x << ' ' << (ans[i].x/(ld)100) << ' ' << ans[i].y/(ld)100 << '\n';
		// cout << vec[i].x << ' ' << (ans[i].x/100) << '.' << (ans[i].x%100) << ' ' << (ans[i].y/100) << '.' << (ans[i].y%100) << '\n';


	return 0;
}
