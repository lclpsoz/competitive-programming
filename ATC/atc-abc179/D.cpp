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

const int MOD = 998244353;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

const int N = 2e5 + 10;

int n, k;
set<int> s;
int bit[N];

void add(int p, int v) {
	for(int i = p; i < N; i +=(i&-i))
		bit[i] = (bit[i]+v)%MOD;
}

int sum(int p) {
	int ret = 0;
	for(int i = p; i; i-= (i&-i))
		ret = (ret+bit[i])%MOD;
	return ret;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
	cin >> n >> k;
	while(k--) {
		int l, r;
		cin >> l >> r;
		while(l <= r) s.insert(l++);
	}
	int lst = -1;
	pii interv = {-1, -1};
	vector<pii> vec;
	for(int v : s) {
		if(interv.y == -1 || interv.y != v-1) {
			if(interv.x != -1)
				vec.push_back(interv);
			interv = {v, v};
		}
		else if (interv.y == v-1)
			interv.y++;
	}
	vec.push_back(interv);

	add(1, 1);
	for(int i = 2; i <= n; i++) {
		// cout << "\ni = " << i << '\n';
		for(pii p : vec) {
			// cout << "p = " << p.x << ' ' << p.y << '\n';
			int l, r;
			r = i-p.x;
			l = max(0, i-p.y-1);
			if(l <= r) {
				// cout << "sum(" << r << ") = " << sum(r) << '\n';
				// cout << "sum(" << l << ") = " << sum(l) << '\n';
				add(i, mod(sum(r) - sum(l)));
			}
		}
	}
	cout << mod(sum(n)-sum(n-1)) << '\n';

	

	return 0;
}
