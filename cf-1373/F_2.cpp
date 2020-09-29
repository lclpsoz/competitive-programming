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

ll a[N], b[N];
ll bit_a[N], bit_b[N];

void add(ll* bit, int p, ll v){
	for(int i = p; i < N; i+=i&-i)
		bit[i] += v;
}

ll sum(ll* bit, int p) {
	ll ret = 0;
	while(p >= 1) {
		ret += bit[p];
		p -= p&-p;
	}
	return ret;
}

bool divide(int l, int r) {
	// cout << "l = " << l << ", r = " << r << '\n';
	if(l == r) {
		// cout << "\ta = " << a[r] << ", b = " << b[l] << '\n';
		return a[r] >= b[l];
	}
	else {
		int md = (l+r)/2;
		// [l, md] and [md+1, r]
		ll a_l = sum(bit_a, md) - sum(bit_a, l-1);
		ll b_l = sum(bit_b, md) - sum(bit_b, l-1);

		ll a_r = sum(bit_a, r) - sum(bit_a, md);
		ll b_r = sum(bit_b, r) - sum(bit_b, md);

		// cout << "\ta_l = " << a_l << ", b_l = " << b_l << '\n';
		// cout << "\ta_r = " << a_r << ", b_r = " << b_r << '\n';

		if(a_l+a_r < b_l+b_r) return false;
		ll ax = min(a_l, b_l);
		a_l -= ax;
		b_l -= ax;

		ax = min(a_r, b_r);
		a_r -= ax;
		b_r -= ax;

		ll in_tranfer = min(min(a[md], b[md+1]), min(a_l, b_r));
		a[md] -= in_tranfer;
		b[md+1] -= in_tranfer;
		add(bit_a, md, -in_tranfer);
		add(bit_b, md+1, -in_tranfer);
		ll out_transfer =  min(min(a[r], b[l]), min(a_r, b_l));
		a[r] -= out_transfer;
		b[l] -= out_transfer;
		add(bit_a, r, -out_transfer);
		add(bit_b, l, -out_transfer);

		return min(divide(l, md), divide(md+1, r));
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
			add(bit_b, i, b[i]);
		}
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
			add(bit_a, i, a[i]);
		}
		cout << (divide(1, n) ? "YES" : "NO") << '\n';
        for(int i = 1; i <= n; i++)
            cout << i << " = " << sum(bit_a, i) << ' ' << sum(bit_b, i) << '\n';
		for(int i = 1; i <= n; i++) {
			add(bit_a, i, -sum(bit_a, i));
			add(bit_b, i, -sum(bit_b, i));
		}
        for(int i = 1; i <= n; i++)
            cout << i << " = " << sum(bit_a, i) << ' ' << sum(bit_b, i) << '\n';
        
	}

	return 0;
}
