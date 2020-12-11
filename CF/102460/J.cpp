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

bitset<505> inp[20], all_vals;

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		string s;
		vi vals;
		all_vals.reset();
		for(int i = 0; i < m; i++) {
			cin >> s;
			inp[i].reset();
			for(int j = 0; j < n; j++) {
				all_vals[j] = (all_vals[j] | (s[j]=='1'));
				inp[i][j] = s[j] == '1';
				// cout << "i = " << i << ", j = " << j << ", inp[i][j] = " << inp[i][j] << '\n';
			}
		}
		bool ans = true;
		for(int i = 0; i < n; i++)
			if(all_vals[i] == 0) {
				ans = false;
				break;
			}
		if(!ans)
			cout << "-1\n";
		else{ 
			int val = 20;
			for(int i = 0; i < (1<<m); i++) {
				all_vals.reset();
				for(int j = 0; j < m; j++)
					if((1<<j)&i)
						for(int k = 0; k < n; k++)
							all_vals[k] = (all_vals[k] | (inp[j][k]));

				ans = true;
				for(int j = 0; j < n; j++)
					if(all_vals[j] == 0) {
						ans = false;
						break;
					}
				if(ans) val = min(val, __builtin_popcount(i));
				// cout << "i = " << i << " " << ans << '\n';
			}
			cout << val << '\n';
		}
	}

	return 0;
}
