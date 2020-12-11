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

const int N = 3e5 + 10;

set<int> mp[N];
int row[N], col[N];

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n, m, q;
	cin >> n >> m >> q;
	while(q--) {
		int x, y;
		cin >> x >> y;
		row[x]++, col[y]++;
		mp[x].insert(y);
	}
	// pii bst = {-1, -1};
	// pii amnt = {-1, -1};
	vpii vec_row, vec_col;
	for(int i = 0; i < N; i++) {
		if(row[i])
			vec_row.push_back({row[i], i});
		if(col[i])
			vec_col.push_back({col[i], i});
	}
	sort(ALL(vec_row));
	sort(ALL(vec_col));
	reverse(ALL(vec_col));
	int ans = 0;
	while(LEN(vec_row)) {
		auto [amount_row, x] = vec_row.back();
		vec_row.pop_back();
		for(int i = 0; i < LEN(vec_col); i++) {
			auto [amount_col, y] = vec_col[i];
			if(mp[x].count(y))
				ans = max(ans, amount_col + amount_row - 1);
			else {
				ans = max(ans, amount_col + amount_row);
				break;
			}
		}
	}
	cout << ans << '\n';

	return 0;
}
