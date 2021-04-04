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

inline int fcmp (ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod (ll x, int m = MOD) {
	int ret = (int)x%m;
	if (ret < 0)
		ret += m;
	return ret;
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

const int N = 3e5 + 10;

int bit[N];

void add (int p, int v) {
	++p;
	for (int i = p; i < N; i+=i&-i)
		bit[i]+=v;
}

int sum (int p) {
	++p;
	int ret = 0;
	for (int i = p; i; i-=i&-i)
		ret += bit[i];
	return ret;
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n;
	cin >> n;
	vi vec(n), bef(n);
	for (int &x : vec)
		cin >> x;
	reverse(ALL(vec));
	ll now = 0;
	for (int v : vec) {
		now += sum(v);
		bef[v] = sum(v);
		// cerr << "v = " << v << ", sum = " << sum(v) << '\n';
		add(v, 1);
	}
	reverse(ALL(vec));

	memset(bit, 0, sizeof bit);
	vector<ll> ans(n);
	ans[0] = now;
	for (int i = 1; i < n; i++) {
		now -= bef[vec[i-1]];
		now += n-1-vec[i-1]-sum(vec[i-1]);
		ans[i] = now;
		add(vec[i-1], 1);
	}
	for (ll v : ans)
		cout << v << '\n';

	return 0;
}
