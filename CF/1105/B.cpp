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

int n, k;
string str;

int main () {
	cin.tie (0);
	ios::sync_with_stdio (false);
	cin >> n >> k;
	cin >> str;
	
	
	int ans = 0;
	for (char c = 'a'; c <= 'z'; c++) {
		int q = 0, now = 0;
		for (int i = 0; i < n; i++) {
			if (str[i] == c)
				++q;
			else
				q = 0;
			if (q == k) {
				++now;
				q = 0;
			}
		}
		ans = max (ans, now);
	}
	cout << ans << '\n';
	
	return 0;
}
