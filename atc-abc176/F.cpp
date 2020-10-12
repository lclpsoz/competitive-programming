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

const int DBG = 0;

int val[2010];

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n;
	vi vec;
	cin >> n;
	for(int i = 0; i < 3*n; i++) {
		int x;
		cin >> x;
		vec.push_back(x);
	}
	reverse(ALL(vec));

	int ans = 0;
	while(LEN(vec)) {
		if(DBG)
			cout << "LEN(vec) = " << LEN(vec) << '\n';
		if(LEN(vec) == 3) {
			ans += (vec[0] == vec[1] and vec[1] == vec[2]);
			vec.pop_back(); vec.pop_back(); vec.pop_back();
		} else {
			int target_val = -1;
			for(int i = LEN(vec)-1; i >= LEN(vec)-3; i--) {
				int q = 0;
				for(int j = i; j >= LEN(vec)-5; j--)
					q+=vec[j]==vec[i];
				if(q==3)
					target_val = vec[i];
			}
			if(target_val == -1) {
				memset(val, 0, sizeof val);
				for(int i = LEN(vec)-1; i >= LEN(vec)-5; i--) {
					if(val[vec[i]] == 0) {
						int q = 0;
						int j = i;
						for(; j and q < 3; j--)
							q += (vec[j] == vec[i]);
						j+=(q==3);
						val[vec[i]] = j;
					}
				}
			} else {
				for(int i = LEN(vec)-1; i >= LEN(vec)-5; i--)
					if(vec[i] != target_val)
						val[vec[i]] = 1;
				val[target_val] = -1;
			}
			sort(vec.end()-5, vec.end(), [&](const int lht, const int rht) {
				return val[lht] > val[rht];
			});
			if(DBG) {
				cout << "target_val = " << target_val << '\n';
				for(int v : vec)
					cout << v << ' ';
				cout << '\n';
			}
			int p = LEN(vec)-3;
			ans += (vec[p] == vec[p+1] and vec[p+1] == vec[p+2]);
			vec.pop_back(); vec.pop_back(); vec.pop_back();
		}
	}
	cout << ans << '\n';

	return 0;
}
