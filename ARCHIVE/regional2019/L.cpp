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

void brute () {
	for (int i = 1; i <= 20; i++) {
		printf (" i = %d, ", i);
		bitset<6> b(i);
		cout << b << ",  \t";
		set<int> st;
		for (int j = 0; j < (1<<i);j++) {
			int now = __builtin_popcount (j);
			if (st.count (now)) st.erase (now);
			else st.insert (now);
		}
		printf ("%d\n", len (st));
	}

}

int main () {
	ll n;
	scanf ("%lld", &n);
	printf ("%lld\n", 1LL<<(__builtin_popcountll(n)));

	return 0;
}
