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

int main () {
	int n, x, y;
	cin >> n >> x >> y;
	string s;
	cin >> s;
	reverse (s.begin(), s.end());
	int ans = 0;
	for (int i = 0; i < x; i++)
		if (i == y and s[i] != '1') ++ans;
		else if (i != y and s[i] != '0') ++ans;
	cout << ans << '\n';


	return 0;
}
