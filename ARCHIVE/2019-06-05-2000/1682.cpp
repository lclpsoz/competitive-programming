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

const int N = 5010;

int t, n;
char s[N];

bool check (int p) {
	
}

bool solve (int p) {
}

int main () {
	s[0] = 'N';
	
	
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d", &n);
		for (int i = 0; i < n; i++)
			putchar (s[i]);
		putchar ('\n');
	}

	return 0;
}
