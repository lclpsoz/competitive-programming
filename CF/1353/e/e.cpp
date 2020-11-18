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



int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		vector<vi> vals(k);
		string s;
		cin >> s;
		int bit_1 = 0;
		for(int i = 0, j = 0; i < LEN(s); i++, j++) {
			if(j == k) j = 0;
			if(s[i] == '1') {
				bit_1++;
				if(!LEN(vals[j]) or vals[j].back() < 0)
					vals[j].push_back(0);
				vals[j].back()++;
			}
			else {
				if(!LEN(vals[j]) or vals[j].back() > 0)
					vals[j].push_back(0);
				vals[j].back()--;
			}
		}
		int ans = 0;
		for(int i = 0; i < k; i++) {
			int mx = 0, acu = 0;
			for(int v : vals[i]) {
				acu += v;
				if(acu < 0) acu = 0;
				mx = max(acu, mx);
			}
			ans = max(ans, mx);
		}
		cout << bit_1-ans << '\n';
	}

	return 0;
}
