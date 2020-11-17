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


string s;
pii pl[2];
int sq = 0;

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> s;
	for(char c : s) {
		if(c == 'Q') {
			if(pl[sq].x == 2) {
				if(sq == 1)
					cout << pl[0].x << " - " << pl[1].x << " (winner)\n";
				else
					cout << pl[0].x << " (winner) - " << pl[1].x << '\n';
			} else {
				string lft = to_string(pl[0].y);
				string rig = to_string(pl[1].y);
				if(sq == 0) lft += "*";
				else rig += "*";
				cout << pl[0].x << " (" << lft << ") - " << pl[1].x << " (" << rig << ")\n";
			}
		} else {
			if(pl[sq].x != 2) {
				if(c == 'R')
					sq = !sq;
				pl[sq].y++;
				if(pl[sq].y == 10 or (pl[sq].y >= 5 and pl[sq].y-pl[!sq].y >= 2))
					pl[sq].y = pl[!sq].y = 0, pl[sq].x++;
			}
		}
	}

	return 0;
}
