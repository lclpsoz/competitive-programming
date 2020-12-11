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

using pic = pair<int, char>;

const int N = 1e5 + 10;

int n, q;
string s;

int lst_upd[N];
set<int> st; // {tm, char}
bitset<N> a_sorted;
char to_char[N];
vpii a_pos;
vector<pair<int, pii>> mp[N];

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	// st.insert({0, 3, 2, 't'});
	// st.insert({0, 1, 0, 'x'});
	// for(auto eq : st)
	// 	cout << eq.tm << '\n';

	cin >> s >> q;
	n = LEN(s);
	for(int tm = 1; tm <= q; tm++) {
		int p, a, k;
		char c;
		cin >> p >> a >> k >> c;
		--p;
		to_char[tm] = c;
		mp[a].push_back({p%a, {p, -tm}});
		mp[a].push_back({p%a, {p + a*k, tm}});
		// all_a.push_back(a);
		a_pos.push_back({a, p%a});
	}
	sort(ALL(a_pos));
	a_pos.resize(unique(ALL(a_pos))-a_pos.begin());

	for(pii _p : a_pos) {
		int a = _p.x, md = _p.y;
		// cout << " a = " << a << ", md = " << md << '\n';
		vector<pair<int, pii>> &now = mp[a];
		if(!a_sorted[a]) {
			sort(ALL(now));
			reverse(ALL(now));
			a_sorted[a] = 1;
		}
		// cout << "LEN = " << LEN(now) << '\n';
		for(int i = md; i < n; i+=a) {
			if(LEN(st) or (LEN(now) and now.back().y.x == i)) {
				// cout << "  " << i << ' ' << now.back().y.x << ' ' << now.back().y.y << '\n';

				while(LEN(now) and now.back().y.x == i and now.back().y.y < 0) {
					st.insert(now.back().y.y);
					now.pop_back();
				}

				int tm = -*st.begin();
				// cout << "  i = " << i << ", tm = " << tm << ", c = " << to_char[tm] << '\n';
				if(tm > lst_upd[i]) {
					lst_upd[i] = tm;
					s[i] = to_char[tm];
				}

				while(LEN(now) and now.back().y.x == i and now.back().y.y > 0) {
					st.erase(-now.back().y.y);
					now.pop_back();
				}
			}
		}
	}
	cout << s << '\n';



	return 0;
}
