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

const int N = 1e5 + 10;

string s;
int pref[N];

int main () {
	cin >> s;
	int up, lo;
	up = lo = 0;
	int lst = -1;
	for (int i = 0; i < len (s); i++)
		if (s[i] >= 'A' and s[i] <= 'Z') {
			++up;
			lst = i;
			pref[i+1] = pref[i];
		}
		else {
			pref[i+1] = pref[i] + 1;
			++lo;
		}

	if (up == 0 or lo == 0)
		printf ("0\n");
	else {
		int ans = min (lo, up);
		int qnt = 0;
		for (int i = lst; i >= 0; i--) {
			ans = min (ans, pref[i+1] + qnt);
			printf ("%d: %d\n", i, pref[i+1] + qnt);
			if (s[i] >= 'A' and s[i] <= 'Z') ++qnt;
		}
		printf ("%d\n", ans);
	}

	return 0;
}
