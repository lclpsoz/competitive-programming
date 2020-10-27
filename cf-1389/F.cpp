#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
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

int max_bip_match(vector<pair<pii, int>> &segments) {
	set<pii> st[2]; // {r, id}
	vector<pair<pair<int, bool>, int>> events; // {{position, is_exiting?}, id}

	for(int i = 0; i < LEN(segments); i++) {
		auto [seg, tp] = segments[i];
		auto [l, r] = seg;
		events.push_back({{l, 0}, i});
		events.push_back({{r, 1}, i});
	}

	sort(ALL(events));

	int sz_mx = 0;
	for(auto [p1, id] : events) {
		auto [pos, is_exit] = p1;
		auto [seg, tp] = segments[id];
		tp--;
		auto [l, r] = seg;
		if(!is_exit)
			st[tp].insert({r, id});
		else if(st[tp].count({r, id})) {
			if(LEN(st[!tp])) {
				sz_mx++;
				auto [r_match, id_match] = *st[!tp].begin();
				st[!tp].erase(st[!tp].begin());
			}
			st[tp].erase({r, id});
		}
	}

	return sz_mx;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n;
	cin >> n;

	vector<pair<pii, int>> segments(n);
	for(auto &p : segments)
		cin >> p.x.x >> p.x.y >> p.y;
	
	cout << n-max_bip_match(segments) << '\n';

	return 0;
}
