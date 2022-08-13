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

int val_to_fill (int pos, vi &vec, vector<ll> &pref, vector<ll> &suf) {
	if (pos == 0) return vec[pos];
	int l = vec[pos-1], r = vec[pos];
	if (pos < LEN(vec)-1)
		r = vec[pos+1];
	ll cur_pref = pref[pos];
	ll cur_suf = suf[pos];
	cerr << "pos = " << pos << ", pref = " << cur_pref << ", suf = " << cur_suf << '\n';
	while (l < r) {
		int md = (l+r+1)/2;
		ll fill_val = (md*1LL*(pos+1)) - cur_pref;
		int qnt_pa = LEN(vec)-pos;
		ll cur_after = (qnt_pa*1LL*((md+qnt_pa-1)+md))/2;
		ll delta_after = cur_suf-cur_after;
		cerr << "  md = " << md << ", fill_val = " << fill_val << ", d_after = " << delta_after << '\n';
		if (fill_val <= delta_after)
			l = md;
		else
			r = md-1;
	}
	ll fill_val = (l*1LL*(pos+1)) - cur_pref;
	int qnt_pa = LEN(vec)-pos;
	ll cur_after = (qnt_pa*1LL*((l+qnt_pa-1)+l))/2;
	ll delta_after = cur_suf-cur_after;
	cerr << "  l = " << l << ", fill_val = " << fill_val << ", d_after = " << delta_after << '\n';
	return (fill_val <= delta_after ? l : -1);
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n;
	cin >> n;
	vi vec(n);
	vector<ll> pref(n), suf(n);
	for (int &v : vec) cin >> v;
	pref[0] = vec[0];
	for (int i = 1; i < n; i++)
		pref[i] = pref[i-1] + vec[i];
	suf[n-1] = vec[n-1];
	for (int i = n-2; i >= 0; i--)
		suf[i] = suf[i+1] + vec[i];

	int l = 0, r = n-1;
	while (l < r) {
		int md = (l+r+1)/2;
		if (val_to_fill(md, vec, pref, suf) != -1)
			l = md;
		else
			r = md-1;
	}
	assert(val_to_fill(l, vec, pref, suf) != -1);
	cout << l << ", val_to_fill = " << val_to_fill(l, vec, pref, suf) << '\n';

	return 0;
}
