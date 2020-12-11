#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
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

const int N = 4e5 + 100;

int bit0[N], bit1[N];

void add(int *t, int p, int v) {
	for(;p < N;p+=p&-p)
		t[p]+=v;
}

void add(int *t, int l, int r, int v) {
	add(t, l, v);
	add(t, r+1, -v);
}

int sum(int *t, int p) {
	int ret = 0;
	for(;p;p-=(p&-p))
		ret += t[p];
	return ret;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n;
	cin >> n;
	vector<pair<pii, bool>> vec;
	vi all_vals;
	for(int i = 0; i < n; i++) {
		int l, r, t;
		cin >> l >> r >> t;
		all_vals.push_back(l);
		all_vals.push_back(r);
		t--;
		vec.push_back({{r, l}, t});
	}
	sort(ALL(all_vals));
	all_vals.resize(unique(ALL(all_vals)) - all_vals.begin());
	sort(ALL(vec));
	vi t0_r, t1_r;
	for(auto &[iter, t] : vec) {
		iter.x = (int)(lower_bound(ALL(all_vals), iter.x)-all_vals.begin())+1;
		iter.y = (int)(lower_bound(ALL(all_vals), iter.y)-all_vals.begin())+1;
		if(t)
			t1_r.push_back(iter.x);
		else
			t0_r.push_back(iter.x);
		// cout << iter.y << ' ' << iter.x << '\n';
	}

	for(auto [iter, t] : vec)
		if(t) {
			auto [r, l] = iter;
			cout << "1: " << l << ' ' << r << '\n';
			int pos_l = (int)(lower_bound(ALL(t0_r), l)-t0_r.begin())+1;
			cout << "1:  [1, " << pos_l << "\n\n";
			add(bit1, 1, pos_l, 1);
		} else {
			auto [r, l] = iter;
			cout << "0: " << l << ' ' << r << '\n';
			int pos_l = (int)(lower_bound(ALL(t1_r), l)-t1_r.begin())+1;
			cout << "0:  [1, " << pos_l << "\n\n";
			add(bit0, 1, pos_l, 1);
		}

	int ans = 0;
	for(int i = 1; i < N; i++) {
		int eval0 = sum(bit0, i);
		int eval1 = sum(bit1, i);
		if(eval0) ans = max(ans, eval0+i-1);
		if(eval1) ans = max(ans, eval1+i-1);
	}
	cout << ans << '\n';

	return 0;
}
