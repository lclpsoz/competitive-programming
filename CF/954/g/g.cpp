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

template<typename T>
const T INF = (is_same<T, int>::value ? 1e9 : 1e18);
const ld EPS = 1e-9;
const int MOD = 1;

inline int fcmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

const int DBG = 0;

vector<ll> nxt_vec(5e5+10);

ll eval(vector<ll> &vec, int len_r, ll mx, ll k) {
	ll sum = 0;
	ll min_k = 0;
	for(int i = 0; i < LEN(vec); i++) {
		sum -= nxt_vec[i];
		nxt_vec[i] = 0;
		ll now = vec[i] + sum;
		ll to_add = mx-now;
		// if(DBG)
		// 	cerr << "min_k = " << min_k << '\n';
		if(to_add > 0) {
			if(i+len_r < LEN(vec))
				nxt_vec[i+len_r] = to_add;
			sum += to_add;
			min_k += to_add;
			if(min_k > k) {
				while(i < LEN(vec)) nxt_vec[i++] = 0;
				return false;
			}
		}
	}

	return true;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n, rn;
	ll k;
	cin >> n >> rn >> k;
	vector<ll> delta(n), vec(n), base(n);
	for(ll &v : base) cin >> v;
	ll cur_sum = 0;
	if(DBG)
		cerr << "vec_1: ";
	for(int i = 0; i < n; i++) {
		cur_sum += base[i];
		if(i+rn < n)
			delta[i+rn] += base[i];
		vec[i] = cur_sum;
		if(DBG)
			cerr << vec[i] << " \n"[i==n-1];
		cur_sum -= delta[i];
		delta[i] = 0;
	}
	cur_sum = 0;
	if(rn)
		for(int i = n-1; i >= 0; i--) {
			if(i-rn >= 0)
				delta[i-rn] += base[i];
			vec[i] += cur_sum;
			cur_sum += base[i];

			cur_sum -= delta[i];
			delta[i] = 0;
		}

	if(DBG) {
		cerr << "vec: ";
		for(int i = 0; i < n; i++)
			cerr << vec[i] << " \n"[i==n-1];
	}
	int len_r = 2*rn+1;
	ll l = 0, r = 2*INF<ll>;
	while(l < r) {
		ll md = (l+r+1)/2;
		if(DBG)
			cerr << l << ' ' << md << ' ' << r << '\n';
		if(eval(vec, len_r, md, k))
			l = md;
		else
			r = md-1;
	}
	cout << l << '\n';


	return 0;
}
