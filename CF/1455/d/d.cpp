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

bool ordered(vi &vec) {
	for(int i = 1; i < LEN(vec); i++)
		if(vec[i-1] > vec[i])
			return false;
	return true;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int t;
	cin >> t;
	while(t--) {
		int n, x;
		cin >> n >> x;
		vi vec(n);
		for(int &v : vec) cin >> v;
		vec.resize(unique(ALL(vec)) - vec.begin());
		if(ordered(vec))
			cout << "0\n";
		else {
			int ans = 0;
			for(int i = 0; i < n; i++)
				if(vec[i] > x) {
					++ans;
					swap(x, vec[i]);
					if(ordered(vec))
						break;
				}
			if(ordered(vec))
				cout << ans << '\n';
			else
				cout << "-1\n";
		}
	}

	return 0;
}
