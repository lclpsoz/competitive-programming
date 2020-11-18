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

void brute(int n) {
	vi vec;
	for(int i = 1; i <= n; i++)
		vec.push_back(i);
	set<vi> st;
	do {
		bool ins = true;
		vi ax = vec;
		// for(int i = 0; i < n/2; i++)
		// 	ax.push_back(vec[i]);
		// cout << LEN(ax) << '\n';
		vi base = ax;
		do {
			if(st.count(ax) == 1) ins = false;
			rotate(ax.begin(), ax.begin()+1, ax.end());
		} while (ins and ax != base);
		if(ins) st.insert(base);
	} while(next_permutation(ALL(vec)));
	for(auto vv : st) {
		for(auto v : vv)
			cout << v << ' ';
		cout << '\n';
	}
	cout << LEN(st) << '\n';
}

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);

	// brute(6);
	int n;
	cin >> n;
	llu ans = 1;
	int now = n-1;
	for(int i = n-1; i >= 1; i--)
		ans = ans*i;
	cout << ans/(n/2) << '\n';

	return 0;
}
