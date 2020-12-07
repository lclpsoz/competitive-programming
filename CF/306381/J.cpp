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



int main () {
	// freopen("abc.in", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n;
	string ss;
	cin >> n >> ss;
	vector<char> s(ALL(ss));

	int a = (int)count(ALL(s), 'a');
	int b = (int)count(ALL(s), 'b');
	int c = (int)count(ALL(s), 'c');

	// cout << a << " " << b << " " << c << endl;

	int ans = INF<int>;

	if(!b)
	{
		if(a && c) ans = -1;
		else ans = 0;
	}
	else
	{
		if(!c || !a) ans = 0;
		else
		{
			int p = int(find(ALL(s), 'b') - s.begin());
			
			{
				bool t = p < a;
				int now = bool(p != a);
				now += (int)count(s.begin(), s.begin() + a + t, 'c');
				ans = min(ans, now);
			}
			{
				bool t = p < c;
				int now = bool(p != c);
				now += (int)count(s.begin(), s.begin() + c + t, 'a');
				ans = min(ans, now);
			}
		}

	}

	cout << ans << endl;

	return 0;
}
