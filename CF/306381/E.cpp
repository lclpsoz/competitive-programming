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

const int N = 3e5 + 10;

set<int> jmp[3];

int main () {
	freopen("orxor.in", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n, q;
	cin >> n >> q;
	vi vals(n+1);
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> vals[i];
		sum += vals[i];
	}
	for (int i = 0; i < 2; i++)
		for (int j = 1; j <= n; j++)
			jmp[i].insert(j);

	while (q--) {
		int opt, l, r;
		cin >> opt >> l >> r;
		if (opt == 1) {
			for (auto it = jmp[0].lower_bound(l); it != jmp[0].end() and *it <= r;) {
				int pos = *it;
				jmp[0].erase(it);
				sum -= vals[pos];
				vals[pos] |= vals[pos]-1;
				sum += vals[pos];
				it = jmp[0].lower_bound(pos);
			}
		}
		else {
			vi nxt_2;
			// First XOR
			for (auto it = jmp[1].lower_bound(l); it != jmp[1].end() and *it <= r;) {
				int pos = *it;
				jmp[1].erase(it);
				jmp[0].erase(pos);
				sum -= vals[pos];
				vals[pos] ^= vals[pos]-1;
				sum += vals[pos];
				nxt_2.push_back(pos);
				it = jmp[1].lower_bound(pos);
			}
			// Second XOR
			for (auto it = jmp[2].lower_bound(l); it != jmp[2].end() and *it <= r;) {
				int pos = *it;
				jmp[2].erase(it);
				sum -= vals[pos];
				vals[pos] ^= vals[pos]-1;
				sum += vals[pos];
				it = jmp[2].lower_bound(pos);
			}

			for (int v : nxt_2)
				jmp[2].insert(v);
		}
		cout << sum << '\n';
	}

	return 0;
}
