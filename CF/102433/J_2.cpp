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

const ld EPS = 1e-3;
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

using uint128_t = __uint128_t;

const int DBG = 0;
const int BASE = 1000000;
const ld A_MIN = 0, A_MAX = 2*acos((ld)-1)*BASE;


int n;
vector<pair<pair<ld, bool>, pair<int, ld>>> pt_sum, pt_sub;
ld cur_sum, cur_sub;
ld delta_sum, delta_sub;

int read_float() {
	string s;
	cin >> s;
	int pos = s.find('.');
	int ret = 0;
	if(pos == string::npos)
		ret = stoi(s)*BASE;
	else {
		string ax = s.substr(pos+1);
		ret = stoi(ax);
		for(int i = 0; i < 6-LEN(ax); i++)
			ret*=10;
		ret += stoi(s.substr(0, pos))*BASE;
	}
	return ret;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> n;

	int l_iter = A_MAX, r_iter = A_MIN;
	for(int i = 0; i < n; i++) {
		// cout << "i = "  << i << '\n';
		// cout.flush();
		ll t = read_float();
		ll s = read_float();
		ll a = read_float();
		if(DBG) {
			cout << t << ' ' << s << ' ' << a << '\n';
		}
		// cout.flush();

		ld delta = (ld)t/s*BASE;
		ld mx = min((ld)A_MAX, a+delta);
		if(cmp(a, mx) == -1) {
			pt_sub.push_back({{(ld)a+EPS*10, false}, {s, (ld)t*BASE-s*(EPS*10)}});
			pt_sub.push_back({{mx, true}, {s, t*BASE-s*(mx-a)}});
		}
		ld mn = max(A_MIN, a-delta);
		if(DBG) {
			cout << "sum = " << mn << ", " << a << '\n';
			cout << "sub = " << a+1 << ", " << mx << "\n\n";
		}
		// l_iter = min(l_iter, mn);a
		// r_iter = max(r_iter, mx);
		pt_sum.push_back({{mn, false}, {s, (t*BASE)-s*(a-mn)}});
		pt_sum.push_back({{a, true}, {s, t*BASE}});
		assert(cmp(a, A_MAX) <= 0);
	}

	sort(ALL(pt_sum));
	reverse(ALL(pt_sum));
	sort(ALL(pt_sub));
	reverse(ALL(pt_sub));

	if(DBG)
		cout << "\n\n______ SIMUL ______\n\n";
	ld ans = 0;
	ld t_lst = -1;
	while(LEN(pt_sum) or LEN(pt_sub)) {
		ld t_now = 1e22;
		if(LEN(pt_sum)) t_now = min(t_now, pt_sum.back().x.x);
		if(LEN(pt_sub)) t_now = min(t_now, pt_sub.back().x.x);
		// assert(t_now <= A_MAX);
		cur_sum += delta_sum*(t_now-t_lst);
		cur_sub -= delta_sub*(t_now-t_lst);
		ans = max(ans, cur_sub + cur_sum);
		t_lst = t_now;
		while(LEN(pt_sum) and cmp(pt_sum.back().x.x, t_now) == 0 and !pt_sum.back().x.y) {
			auto [info, p] = pt_sum.back();
			pt_sum.pop_back();
			auto [s, s_val] = p;
			cur_sum += s_val;
			delta_sum += s;
		}
		while(LEN(pt_sub) and cmp(pt_sub.back().x.x, t_now) == 0 and !pt_sub.back().x.y) {
			auto [info, p] = pt_sub.back();
			pt_sub.pop_back();
			auto [s, s_val] = p;
			cur_sub += s_val;
			delta_sub += s;
		}

		ans = max(ans, cur_sub + cur_sum);

		while(LEN(pt_sum) and cmp(pt_sum.back().x.x, t_now) == 0 and pt_sum.back().x.y) {
			auto [info, p] = pt_sum.back();
			pt_sum.pop_back();
			auto [s, s_val] = p;
			assert(cmp(cur_sum, s_val, 4) >= 0);
			cur_sum -= s_val;
			delta_sum -= s;
			if(DBG)
				cout << "rem_sum: s_val = " << s_val << '\n';
		}
		while(LEN(pt_sub) and cmp(pt_sub.back().x.x, t_now) == 0 and pt_sub.back().x.y) {
			auto [info, p] = pt_sub.back();
			pt_sub.pop_back();
			auto [s, s_val] = p;
			// cout << cur_sub << ' ' << s_val << '\n';
			cout.flush();
			assert(cmp(cur_sub, s_val, 4) >= 0);
			cur_sub -= s_val;
			delta_sub -= s;
		}

		ans = max(ans, cur_sub + cur_sum);
	}

	cout << fixed << ans/1e12 << '\n';
	

	return 0;
}
