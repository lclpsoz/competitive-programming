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

string s;
int n;
vector<int> vec;

bool checkPal (int l, int r) {
	if (l == r) return false;
	int nn = (r - l + 1);
	for (int i = 0; i < nn/2; i++)
		if (s[l+i] != s[l+nn-1-i]) return false;
	return true;
}

bool check (int x, int y) {
	if (checkPal (x, y)) return true;
	for (int i = x+1; i < y-1; i++)
		if (check (x, i) and check (i+1, y)) return true;
	return false;
}

int main () {
	// ios::sync_with_stdio (false);
	cin >> n >> s;
	cout << check (0, 3) << ' ' << checkPal(0, 3) << '\n';
	ll ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++) {
			ans += check (i, j);
			printf ("%d %d -> %d\n", i, j, ans);
		}
	printf ("%lld\n", ans);

	return 0;
}