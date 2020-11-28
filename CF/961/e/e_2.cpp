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

const int N = 2e5 + 10;

int bit[N];

int sum(int p) {
	int ret = 0;
	for(int i = p; i; i-=i&-i)
		ret += bit[i];
	return ret;
}

void add(int p, int v) {
	for(int i = p; i < N; i+=i&-i)
		bit[i] += v;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n;
	cin >> n;
	vi vec(n);
	vector<vi> to_rem(n+1);

	for(int &v : vec) {
		cin >> v;
		v = min(v, n);
	}

	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		ans += sum(vec[i-1]);
		// cerr << "i = " << i << ", sum = " << sum(vec[i-1]) << '\n';
		for(int v : to_rem[i])
			add(v, -1);
		if(vec[i-1] > i) {
			add(i, 1);
			to_rem[vec[i-1]].push_back(i);
		}
	}

	cout << ans << '\n';

	return 0;
}
