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

const int N = 2e5 + 10;

int n;
int a[N];
multiset<int> st;

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf ("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		st.insert (x);
	}
	for (int i = 0; i < n; i++) {
		auto it = st.begin();
		auto it2 = st.lower_bound (n-a[i]);
		if (it2 != st.end() and (*it + a[i])%n > (*it2 + a[i])%n)
			swap (it, it2);
		printf ("%d ", (*it + a[i])%n);
		st.erase (it);
	}

	return 0;
}
