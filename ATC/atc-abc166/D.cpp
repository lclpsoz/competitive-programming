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

ll pow5(ll x) {
	ll ret = 1;
	for(int i = 0; i < 5; i++) ret *= x;
	return ret;
}


int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);
	ll x;
	cin >> x;
	set<ll> st;
	for(int i = 0; i < 200; i++)
		for(int j = 0; j <= i; j++) {
			if(pow5(i)-pow5(j) == x) {
				cout << i << ' ' << j << '\n';
				exit(0);
			} else if (pow5(i)+pow5(j) == x) {
				cout << i << ' ' << -j << '\n';
				exit(0);
			}
			// if(pow5(i)-pow5(j) < 2e9)
			// // 	printf("i = %3d, j = %3d, %lld\n", i, j, pow5(i)-pow5(j));
			// // st.insert(pow5(i)-pow5(j));
			// // // printf("-------------------------------\n");
			// // if(pow5(i)+pow5(j) < 2e9)
			// // 	printf("|i = %d, j = %d, %lld\n", i, j, pow5(i)+pow5(j));

		}

	// for(ll v : st)
	// 	printf("%lld\n", v);

	return 0;
}
