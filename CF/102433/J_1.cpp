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

using uint128_t = __uint128_t;

const int DBG = 0;
const int BASE = 1000000, A_MIN = 0, A_MAX = 6283185;


int n;
vector<pair<int, ll>> pt_sum[A_MAX+4], pt_sub[A_MAX+4];
pair<ll, int> cur_sum, cur_sub;
ll delta_sum, delta_sub;

int read_float() {
	string s;
	cin >> s;
	int pos = s.find('.');
	int ret = 0;
	if(pos == string::npos)
		ret = stoi(s)*1000000;
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
		int t = read_float();
		int s = read_float();
		int a = read_float();
		if(DBG) {
			cout << t << ' ' << s << ' ' << a << '\n';
		}
		// cout.flush();

		int delta = t/s*BASE;
		int mx = min(A_MAX, a+delta);
		if(t%s == 0) mx--;
		if(a < mx) {
			pt_sub[a+1].push_back({s, t*1LL*BASE-s*1LL*(1)});
			pt_sub[mx].push_back({s, -(t*1LL*BASE-s*1LL*(mx-a))});
		}
		int mn = max(A_MIN, a-delta);
		if(t%s == 0) mn++;
		if(DBG) {
			cout << "sum = " << mn << ", " << a << '\n';
			cout << "sub = " << a+1 << ", " << mx << "\n\n";
		}
		l_iter = min(l_iter, mn);
		r_iter = max(r_iter, mx);
		pt_sum[mn].push_back({s, t*1LL*BASE-s*1LL*(a-mn)});
		pt_sum[a].push_back({s, -(t*1LL*BASE)});
	}

	if(DBG)
		cout << "\n\n______ SIMUL ______\n\n";
	uint128_t ans = 0;
	for(int i = A_MIN; i <= A_MAX; i++) {
		// cout << "i = " << i << '\n';
		// cout.flush();
		for(auto [s, s_val] : pt_sum[i])
			if(s_val > 0) {
				cur_sum.x += s_val;
				delta_sum += s;
				if(DBG)
					cout << "add_sum: s_val = " << s_val << '\n';
			}
		for(auto [s, s_val] : pt_sub[i])
			if(s_val > 0) {
				cur_sub.x += s_val;
				delta_sub += s;
			}

		uint128_t cur = cur_sub.x + cur_sum.x;
		ans = max(ans, cur);

		for(auto [s, s_val] : pt_sum[i])
			if(s_val < 0) {
				cur_sum.x += s_val;
				if(DBG)
					cout << "rem_sum: s_val = " << s_val << '\n';
				delta_sum -= s;
			}
		for(auto [s, s_val] : pt_sub[i])
			if(s_val < 0) {
				cur_sub.x += s_val;
				delta_sub -= s;
			}

		cur_sum.x += delta_sum;
		cur_sub.x -= delta_sub;
		if(ans and i >= l_iter and i <= r_iter and i%10000 == 0) {

			if(DBG) {
				cout << "i = " << i << '\n';
				cout << "  cur = " << cur_sub.x << ' ' << cur_sum.x << '\n';
				cout << "    ans = " << (ll)ans << "\n\n";
			}
			cout.flush();
		}
	}

	ll it = ans/(BASE*1LL*BASE);
	cout << it << '.';
	ll fl = ans%(BASE*1LL*BASE);
	for(int i = 0; i < 12-LEN(to_string(fl)); i++)
		cout << '0';
	cout << fl << '\n';
	

	return 0;
}
