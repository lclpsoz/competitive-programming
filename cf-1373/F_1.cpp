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

// WARNING: a, b are inverted, when compared to the question!!!

const int N = 1e6 + 10;

int a[N], b[N], pref_a[N], pref_b[N];

bool divide(int l, int r, int rem, int add) {
	cout << "l = " << l << ", r = " << r << ", rem = " << rem << ", add = " << add << '\n';
	if(l == r) {
		b[l] -= add;
		a[r] -= rem;
		cout << "\ta = " << a[r] << ", b = " << b[l] << '\n';
		return a[r] >= b[l];
	}
	else {
		int md = (l+r)/2;
		// [l, md] and [md+1, r]
		int a_l = pref_a[md] - pref_a[l-1];
		int b_l = pref_b[md] - pref_b[l-1];

		int a_r = pref_a[r] - pref_a[md];
		int b_r = pref_b[r] - pref_b[md];


		b_l -= add;
		a_r -= rem;

		cout << "\ta_l = " << a_l << ", b_l = " << b_l << '\n';
		cout << "\ta_r = " << a_r << ", b_r = " << b_r << '\n';

		if(a_l+a_r < b_l+b_r) return false;
		int ax = min(a_l, b_l);
		a_l -= ax;
		b_l -= ax;

		ax = min(a_r, b_r);
		a_r -= ax;
		b_r -= ax;

		int in_tranfer = 	min(min(a[md], b[md+1]), min(a_l, b_r));
		int out_transfer =  min(min(a[r]-rem, b[l]-add), min(a_r, b_l));
		return min(	divide(l, md, 	in_tranfer, 
									min(b[l], min(a_r, b_l)+add)),
					divide(md+1, r, min(a[r], min(a_r, b_l)+rem),
									in_tranfer));
	}
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> b[i];
			pref_b[i] = pref_b[i-1] + b[i];
		}
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
			pref_a[i] = pref_a[i-1] + a[i];
		}
		cout << (divide(1, n, 0, 0) ? "YES" : "NO") << '\n';
	}

	return 0;
}
