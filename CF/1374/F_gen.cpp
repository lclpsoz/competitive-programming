#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

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



int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);
	mt19937_64 rng((llu)chrono::steady_clock::now().time_since_epoch().count());
	int n = 5;
	uniform_int_distribution<int> disInt(1, n);
	vector<int> vec;
	for(int i = 1; i < n; i++)
		vec.push_back(disInt(rng));
	vec.push_back(vec.back());
	vector<vector<int>> ax;
	do {
		ax.push_back(vec);
		for(int i = 0; i < n; i++)
			vec[i] = disInt(rng);
		if(LEN(ax) > 10000) break;
	// } while(next_permutation(vec.begin(), vec.end()));
	} while(1);
	printf("%d\n", LEN(ax));
	for(vector<int> &x : ax) {
		printf("%d\n", n);
		for(int i = 0; i < n; i++)
			printf("%d%c", x[i], " \n"[i==n-1]);
	}


	return 0;
}
