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

const ld EPS = 1e-7;
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

const int DBG = 0;
const ld A_MIN = 0, A_MID = acos((ld)-1), A_MAX = 2*acos((ld)-1);


int n;
vector<pair<pair<ld, bool>, pair<ld, ld>>> pt_sum, pt_sub;
ld cur_sum, cur_sub;
ld delta_sum, delta_sub;

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> n;
	int l_iter = A_MAX, r_iter = A_MIN;
	for(int i = 0; i < n; i++) {
		ld t, s, a;
		cin >> t >> s >> a;
		if(DBG)
			cout << t << ' ' << s << ' ' << a << '\n';
		if(cmp(t, 0) == 1) {
			ld delta;
			delta = min(A_MID, t/s);

			ld mx = a+delta;
			if(cmp(mx, A_MAX) == 1) {
				pt_sub.push_back({{A_MAX, true}, {s, t-s*(A_MAX-a)}});

				pt_sub.push_back({{0, false}, {s, t-s*(A_MAX-a)}});
				pt_sub.push_back({{mx-A_MAX, true}, {s, t-s*(mx-a)}});
			} else
				pt_sub.push_back({{mx, true}, {s, t-s*(mx-a)}});

			ld mn = a-delta;
			if(cmp(mn, A_MIN) == -1) {
				pt_sum.push_back({{0, false}, {s, t-s*a}});
				pt_sum.push_back({{a, true}, {s, t}});

				pt_sum.push_back({{mn+A_MAX, false}, {s, t-s*(abs(mn)+a)}});
				pt_sum.push_back({{A_MAX, true}, {s, t-s*a}});
			} else {
				pt_sum.push_back({{mn, false}, {s, t-s*(a-mn)}});
				pt_sum.push_back({{a, true}, {s, t}});
			}
			assert(cmp(a, A_MAX) <= 0);
			if(DBG) {
				cout << "sum = " << mn << ", " << a << '\n';
				cout << "sub = " << a << ", " << mx << "\n\n";
			}
		}
	}

	auto comp = [&](const pair<pair<ld, bool>, pair<int, ld>> &lhs, const pair<pair<ld, bool>, pair<int, ld>> &rhs) {
		if(cmp(lhs.x.x, rhs.x.x) == -1)
			return true;
		else if(cmp(lhs.x.x, rhs.x.x) == 1)
			return false;
		return lhs.x.y < rhs.x.y;
	};

	sort(ALL(pt_sum), comp);
	reverse(ALL(pt_sum));
	sort(ALL(pt_sub), comp);
	reverse(ALL(pt_sub));

	if(DBG) {
		cout << "pt_sum:\n";
		for(auto p : pt_sum)
			cout << p.x.x << ' ' << p.x.y << ",\t s = " << p.y.x << ", s_val = " << p.y.y << '\n';
		cout << "\npt_sub:\n";
		for(auto p : pt_sub)
			cout << p.x.x << ' ' << p.x.y << ",\t s = " << p.y.x << ", s_val = " << p.y.y << '\n';
	}

	if(DBG)
		cout << "\n\n______ SIMUL ______\n\n";
	ld ans = 0;
	ld t_lst = 0;
	while(LEN(pt_sum) or LEN(pt_sub)) {
		ld t_now = 1e22;
		if(LEN(pt_sum)) t_now = min(t_now, pt_sum.back().x.x);
		if(LEN(pt_sub)) t_now = min(t_now, pt_sub.back().x.x);
		if(DBG) {
			cout << "t_now = " << t_now << '\n';
			cout << "  delta_sum = " << delta_sum << ", delta_sub = " << delta_sub << '\n';
			cout.flush();
		}
		cur_sum += delta_sum*(t_now-t_lst);
		cur_sub -= delta_sub*(t_now-t_lst);
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
		
		while(LEN(pt_sum) and cmp(pt_sum.back().x.x, t_now) == 0 and pt_sum.back().x.y) {
			auto [info, p] = pt_sum.back();
			pt_sum.pop_back();
			auto [s, s_val] = p;
			cur_sum -= s_val;
			delta_sum -= s;
			cur_sub += s_val;
			delta_sub += s;
		}
		while(LEN(pt_sub) and cmp(pt_sub.back().x.x, t_now) == 0 and pt_sub.back().x.y) {
			auto [info, p] = pt_sub.back();
			pt_sub.pop_back();
			auto [s, s_val] = p;
			cur_sub -= s_val;
			delta_sub -= s;
		}
		if(DBG) {
			cout << "  cur_sum = " << cur_sum << ", cur_sub = " << cur_sub << "\n\n";
			cout.flush();
		}
		ans = max(ans, cur_sub + cur_sum);
	}

	cout << fixed << ans << '\n';
	

	return 0;
}
