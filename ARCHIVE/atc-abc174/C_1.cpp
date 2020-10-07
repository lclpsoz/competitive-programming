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

const int MOD = 1e9 + 7;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

int qnt_mods = 2;
int mods[2] = {(int)1e9+7, (int)1e9 + 37};
const int N = 5e6/qnt_mods;

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);
	int k;
	cin >> k;
	vector<int> now(qnt_mods, 7);
	vector<int> base(qnt_mods, 10);
	vector<pii> vals[qnt_mods];
	for(int i = 1; i < N; i++) {
		for(int j = 0; j < qnt_mods; j++) {
			// cout << i << ": " << now[j] << '\n';
			vals[j].push_back({now[j], i});
			now[j] = (now[j] + 7LL*base[j])%mods[j];
			base[j] = (10LL*base[j])%mods[j];
		}
	}
	for(int j = 0; j < qnt_mods; j++)
		sort(ALL(vals[j]));
	now = vector<int>(qnt_mods, k);
	for(int i = 0; i < N; i++) {
		int match = -1;
		for(int j = 0; j < qnt_mods; j++) {
			// cout << now[j] << '\n';
			auto it = lower_bound(ALL(vals[j]), make_pair(now[j], 0));
			if(j == 0 and it->x == now[j]) {
				match = it->y;
				// cout << "| " << it->x << ' ' << it->y << '\n';
				// cout << it->y << '\n';
				// exit(0);
			} else if(j > 0 and (it->x != now[j] or match != it->y))
				match = -1;
			now[j] = (now[j]+k)%mods[j];
		}
		if(match != -1) {
			cout << match << '\n';
			exit(0);
		}
	}
	cout << "-1\n";

	return 0;
}
