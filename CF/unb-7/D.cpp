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
int o;

int main () {
	cin >> s;
	bool prt = true;
	for (int i = 0; i < len (s); i++) {
		if (s[i] == 'O') {++o; prt = false; }
		// printf ("o: %d\n", o);
		if (i and i%3 == 2)
			printf ("fizz");
		if (!prt and o and o%5 == 0) {
			printf ("busao");
			prt = true;
		}
		else if (!(i and i%3 == 2))
			printf ("%d", i+1);
		putchar ('\n');
	}

	return 0;
}
