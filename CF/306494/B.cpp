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
const ld EPS = 1e-12;
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

const int N = 1e3 + 10;

int k;
int total;
int vals[N];

ld eval(ld x) {
	ld ret = 0;
	for(int i = 0; i < k; i++)
		ret += (ld)vals[i]/(x+vals[i]);
	// cerr << "ret = " << ret << ", x = " << x << '\n';
	return ret*x;
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);

	cin >> k >> total;
	for(int i = 0; i < k; i++)
		cin >> vals[i];
	
	// for(ld i = 0; i < 10; i++)
	// 	cout << i << ' ' << eval(i) << '\n';

	ld l = 0, r = 1e18;
	while(fcmp(l, r)) {
		ld md = (l+r)/2;
		// cerr << eval(md) << '\n';
		if(eval(md) < total)
			l = md;
		else
			r = md;
	}
	cout << fixed << l << '\n';

	return 0;
}
