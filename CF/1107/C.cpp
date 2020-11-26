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

const int N = 2e5 + 100;

int vals[N];
int qnt[1000];
char s[N];
multiset<int> st;

int main () {
	int k, n;
	scanf ("%d %d", &k, &n);
	for (int i = 0; i < k; i++)
		scanf ("%d", &vals[i]);
	
	ll ans = 0;
	scanf (" %s", s);
// 	printf ("%s\n", s);
	st.insert (vals[0]);
	for (int i = 1; i < k; i++)
		if (s[i] != s[i-1]) {
			while (len (st) > n) st.erase (st.begin());
			while (!st.empty()) {
				ans += *st.begin();
// 				printf ("%lld\n", ans);
				st.erase (st.begin());
			}
			st.insert (vals[i]);
		} else
			st.insert (vals[i]);
	
	while (len (st) > n) st.erase (st.begin());
	while (!st.empty()) {
		ans += *st.begin();
// 		printf ("%lld\n", ans);
		st.erase (st.begin());
	}
	
	printf ("%lld\n", ans);

	return 0;
}
