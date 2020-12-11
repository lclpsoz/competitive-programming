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

struct segments {
	int n;
	set<pair<pii, int>> segs;
	set<pii> freq;
	vi cnt;
	segments (int _n) : n(_n) {
		segs.insert({{1, n}, 1});
		freq.insert({n, 1});
		cnt = vi(1e5 + 1);
		cnt[1] = n;
	}

	void add (int l, int r, int new_color) {
		auto it = segs.lower_bound({{l, -1}, -1});
		if (it == segs.end() or it->x.x > l) --it;
		vector<pair<pii, int>> segs_inter;
		do {
			segs_inter.push_back(*it);
			++it;
		} while (it != segs.end() and it->x.x <= r);
		for (auto s : segs_inter)
			segs.erase(s);

		if (segs_inter.front().x.x < l) {
			if (segs_inter.front().y == new_color)
				l = segs_inter.front().x.x;
			else {
				segs.insert({{segs_inter.front().x.x, l-1}, segs_inter.front().y});
				segs_inter.front().x.x = l;
			}
		}
		if (segs_inter.back().x.y > r) {
			if (segs_inter.back().y == new_color)
				r = segs_inter.back().x.y;
			else {
				segs.insert({{r+1, segs_inter.back().x.y}, segs_inter.back().y});
				segs_inter.back().x.y = r;
			}
		}

		for (auto [interval, color] : segs_inter) {
			auto [a, b] = interval;
			freq.erase({cnt[color], color});
			cnt[color] -= b-a+1;
			freq.insert({cnt[color], color});
		}

		freq.erase({cnt[new_color], new_color});
		cnt[new_color] += r-l+1;
		freq.insert({cnt[new_color], new_color});
		segs.insert({{l, r}, new_color});
	}

	int get_freq (int color) {
		return cnt[color];
	}

	int get_most_freq_freq () {
		return freq.rbegin()->x;
	}
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n, q;
	cin >> n >> q;
	segments segs(n);
	while (q--) {
		int opt;
		cin >> opt;
		if (opt == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			segs.add(l, r, x);
		}
		else if (opt == 2) {
			int x;
			cin >> x;
			cout << segs.get_freq(x) << '\n';
		}
		else
			cout << segs.get_most_freq_freq() << '\n';
		// cerr << "  AFTER q = " << q << '\n';
		// for (auto s : segs.segs)
		// 	cerr << "(" << s.x.x << ", " << s.x.y << ") = " << s.y << " | ";
		// cerr << '\n';
		// cerr << '\n';
	}

	return 0;
}
