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

vector<int> ans;
set<ll> st;

int main () {
	int qq;
	scanf ("%d", &qq);
	while (qq--) {
		ll x;
		scanf ("%lld", &x);
		int ans = 0;
		while (x%2 == 0) x/=2, ++ans;
		while (x%3 == 0) x/=3, ans+=2;
		while (x%5 == 0) x = x/=5, ans+=3;
		printf ("%d\n", x == 1 ? ans : -1);
	}
	

	return 0;
}
