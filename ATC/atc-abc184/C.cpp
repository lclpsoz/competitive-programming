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

bool adj (ll a, ll b, ll c, ll d) {
	return (a+b == c+d) or
		(a-b == c-d) or
		(abs(a-c) + abs(b-d) <= 3);
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a == c and b == d)
		cout << "0\n";
	else if (adj (a, b, c, d))
		cout << "1\n";
	else if ((a+b)%2 == (c+d)%2)
		cout << "2\n";
	else {
		for (ll i = a-5; i <= a+5; i++)
			for (ll j = b-5; j <= b+5; j++)
				if (adj(i, j, a, b) and adj(i, j, c, d)) {
					cout << "2\n";
					exit(0);
				}
		cout << "3\n";
	}

	return 0;
}
