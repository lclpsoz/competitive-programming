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

pii mov (pii st, char dir) {
	if (dir == 'L')
		st.x--;
	else if (dir == 'R')
		st.x++;
	else if (dir == 'U')
		st.y++;
	else if (dir == 'D')
		st.y--;

	return st;
}

bool simulate (string &s, pii blocked) {
	pii pos = {0, 0};
	for (char dir : s) {
		pii nxt = mov(pos, dir);
		if (nxt != blocked)
			pos = nxt;
	}
	return pos == make_pair(0, 0);
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		pii pos = {0, 0};
		vpii positions;
		for (char dir : s) {
			pos = mov(pos, dir);
			if (pos != make_pair(0, 0)) {
				positions.push_back(pos);
				// cerr << "  try: " << pos.x << ' ' << pos.y << '\n';
			}
		}
		if (pos == make_pair(0, 0))
			cout << INF<int> << ' ' << INF<int> << '\n';
		else {
			pii ans = {0, 0};
			for (pii blocked : positions)
				if (simulate(s, blocked)) {
					// cerr << "blocked: " << blocked.x << ' ' << blocked.y << '\n';
					ans = blocked;
					break;
				}
			cout << ans.x << ' ' << ans.y << '\n';
		}
	}

	return 0;
}
