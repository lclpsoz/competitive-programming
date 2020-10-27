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

using pp = pair<pii, int>;


int cost_vec(vector<pp> &vec) {
	int ret = 0 ;
	for(auto &p : vec)
		for(int i = p.x.x; i <= p.x.y; i++)
			ret += abs(p.y-i);
	return ret;
}

int apply_new_inter(vector<pp> &vec, pp new_inter) {
	pp lst = new_inter;
	int p = LEN(vec)-1;
	while(p >= 0) {
		int dif = vec[p].x.y-lst.x.x+1;
		if(dif > 0) {
			vec[p].x.x -= dif;
			vec[p].x.y -= dif;
		}
		lst = vec[p];
		--p;
	}
	vec.push_back(new_inter);
}

int cost_insert(vector<pp> vec, pp new_inter) {
	apply_new_inter(vec, new_inter);
	if(LEN(vec) and vec[0].x.x < 1)
		return 1e9 + 1;
	else
		return cost_vec(vec);
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		map<int, int> mp;
		for(int i = 0; i < n; i++) {
			int x;
			cin >> x;
			mp[x]++;
		}
		int l, r;
		int ans = 0;
		l = 0, r = 500;
		vector<pp> vec;
		for(auto [x, sz] : mp) {
			// pp now = {{x-sz/2, x+(sz-1)/2}, x};
			pp bst;
			int cost_bst = 1e9;
			for(int i = 1; i <= 201; i++) {
				pp now = {{i, i+sz-1}, x};
				int test = cost_insert(vec, now);
				if(test < cost_bst) {
					bst = now;
					cost_bst = test;
				}
			}
			apply_new_inter(vec, bst);
		}
		// for(auto p : vec)
		// 	cout << "  p.x = " << p.x.x << ' ' << p.x.y << ", v = " << p.y << '\n';
		cout << cost_vec(vec) << '\n';
	}

	return 0;
}
