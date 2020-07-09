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
		// 0  1  2  3  4  5  6  7  8  9
int v[] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};
string s;

int main () {
	cin >> s;
	int ans = v[s[0]-'0']*v[s[1]-'0'];
	printf ("%d\n", ans);

	return 0;
}
