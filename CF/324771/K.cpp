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



int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n; cin >> n;
	vi a(n), b(n);
	for(int& i : a) cin >> i;
	for(int& i : b) cin >> i;

	for(int i = 1; i < n; i++)
	{
		a[i] = max(a[i], a[i - 1]);
		b[i] = max(b[i], b[i - 1]);
	}

	int m;
	cin >> m;
	
	vi c(m), d(m);
	for(int& i : c) cin >> i;
	for(int& i : d) cin >> i;

	for(int i = 0; i < m; i++)
	{
		auto it1 = upper_bound(ALL(a), c[i]) - a.begin();
		auto it2 = upper_bound(ALL(b), d[i]) - b.begin();
	
		if(it1 < it2) cout << "Mike\n";
		else if(it1 > it2) cout << "Constantine\n";
		else cout << "Draw\n";
	}

	return 0;
}
