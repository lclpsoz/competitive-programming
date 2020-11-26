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

char str[1010];

int main () {
	scanf ("%s", str);
	int posVert = 0, posHor = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '0') {
			printf ("1 %d\n", posVert+1);
			posVert++;
			posVert%=4;
		} else {
			printf ("3 %d\n", posHor+1);
			posHor+=2;
			posHor%=4;
		}
	}

	return 0;
}
