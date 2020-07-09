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
	int sth, stm, enh, enm;
	scanf ("%d:%d %d:%d", &sth, &stm, &enh, &enm);
	stm += sth*60;
	enm += enh*60;
	
	stm = (stm+enm)/2;
	sth = stm/60;
	stm%=60;
	printf ("%02d:%02d\n", sth, stm);

	return 0;
}
