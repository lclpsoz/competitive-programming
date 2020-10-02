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

const int N = 1e5 + 10;

int q;
string s;
int msks[1000];
int amounts[1000][30];

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> s >> q;
	int n = LEN(s);
	for(int i = 0; i < n; i++) s[i] -= 'a';

	int sq = sqrt(n);
	for(int i = 0; i < n; i++) {
		int block = i/sq;
		msks[block] |= 1<<s[i];
		amounts[block][s[i]]++;
	}

	while(q--) {
		int opt;
		cin >> opt;
		if(opt == 1) {
			int pos;
			char c;
			cin >> pos >> c;
			// cout << pos << ' ' << c << '\n';
			pos--;
			c-='a';
			if(c != s[pos]) {
				int block = pos/sq;
				msks[block] |= 1<<c;
				amounts[block][c]++;
				amounts[block][s[pos]]--;
				if(!amounts[block][s[pos]])
					msks[block] ^= 1<<s[pos];
				s[pos] = c;
			}
		} else {
			int l, r;
			cin >> l >> r;
			--l, --r;
			int count = 0;
			// for(int i = l; i <= r; i++)
			// 	cout << i << ": " << (int)s[i] << '\n';

			while(l%sq and l <= r)
				count |= (1<<s[l++]);

			while(l+sq-1 <= r) {
				count |= msks[l/sq];
				// cout << bitset<5>(msks[l/sq]) << '\n';
				l+=sq;
			}

			while(l <= r)
				count |= (1<<s[l++]);

			cout << __builtin_popcount(count) << '\n';
		}
	}

	return 0;
}
