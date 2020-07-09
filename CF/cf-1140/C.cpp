#include "bits/stdc++.h"
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 3e5+10;

vector<pii> vec;
ll acu[N];
multiset<int> mst;

int main () {
	int n, k;
	scanf ("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf ("%d %d", &x, &y);
		vec.push_back ({y, x});
	}
	
	if (k == 1) {
		ll ans = -1;
		for (pii p : vec)
			ans = max (ans, p.x * 1LL * p.y);
		printf ("%lld\n", ans);
	} else {
		ll length = 0;
		ll ans = 0;
		sort (vec.begin(), vec.end(), greater<pii>());

		for (int i = 0; i < n-1; i++) {
			int now = vec[i].y;
			if (len (mst) == k-1) {
				auto it = mst.begin();
				if (*it < now) {
					length -= *it;
					mst.erase (it);
					mst.insert (now);
					length += now;
				}
			} else {
				mst.insert (now);
				length += now;
			}
			acu[i+1] = length;
		}
		
		for (int i = 0; i < n; i++) {
			pii p = vec.back();
//  			printf ("b = %d, t = %d, acu = %lld\n", p.x, p.y, acu[n-i-1]);
			vec.pop_back ();
			ans = max (ans, (acu[n-i-1] + p.y) * 1LL * p.x);
// 			length -= p.y;
// 			if (i < n-k)
// 				ans = -1;
// 			printf ("%lld\n", ans);
		}
		printf ("%lld\n", ans);
	}
	
	return 0;
}
