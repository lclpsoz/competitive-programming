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

int f_brute(vi vec) {
	int ret = 1e9;
	if(LEN(vec) == 2)
		ret = (vec[0]+vec[1]+1)/2;
	else {
		for(int i = 0; i < LEN(vec); i++)
			for(int j = i+1; j < LEN(vec); j++) {
				vi nxt = {(vec[i]+vec[j]+1)/2};
				for(int k = 0; k < LEN(vec); k++)
					if(k != i and k != j)
						nxt.push_back(vec[k]);
				ret = min(ret, f_brute(nxt));
			}
	}
	if(ret == 2) {
		for(int v : vec)
			cout << v << ' ';
		cout << '\n';
	}
	return ret;
}

int brute(int n) {
	vi base;
	for(int i = 1; i <= n; i++)
		base.push_back(i);
	return f_brute(base);
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	// for(int i = 5; i <= 5; i++)
	// 	cout << i << " = " << brute(i) << '\n';
	// exit(0);
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		cout << 2 << '\n';
		vi vec;
		for(int i = 1; i <= n; i++)
			vec.push_back(i);
		for(int i = n-1; i >= 1; i--) {
			cout << vec[i] << ' ' << vec[i-1] << '\n';
			vec[i-1] = (vec[i]+vec[i-1]+1)/2;
		}
	}

	return 0;
}
