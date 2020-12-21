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
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);
	
	int x, y, z;
	cin >> x >> y >> z;
	int m, n;
	string s;
	cin >> m >> n >> s;

	auto check = [&](int q)
	{
		vi h(q, m);
		int p1 = 0, p2 = 0, p3 = 0;
		for(char c : s)
		{
			if(c == 'F')
			{
				while(p1 < q && h[p1] < x) p1++;
				if(p1 == q) return false;
				h[p1] -= x;
			}
			else if(c == 'A')
			{
				while(p2 < q && h[p2] < y) p2++;
				if(p2 == q) return false;
				h[p2] -= y;
			}
			else
			{
				while(p3 < q && h[p3] < z) p3++;
				if(p3 == q) return false;
				h[p3] -= z;
			}
		}

		return true;
	};

	int l = 1, r = n, ans = 0;
	while(l <= r)
	{
		int mid = (l + r) / 2;
		if(check(mid))
			ans = mid, r = mid - 1;
		else
			l = mid + 1;
	}
	cout << ans << endl;

	return 0;
}
