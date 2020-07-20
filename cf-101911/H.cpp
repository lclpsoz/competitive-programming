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
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

int n, m;
int xx1, yy1, xx2, yy2;

int main () {
	scanf("%d %d", &n, &m);
	scanf("%d %d %d %d", &xx1, &yy1, &xx2, &yy2);

	int h = xx2 - xx1 + 1;
	int ax = ((yy1 > 1 and yy1%2 == 0)*h);
	ax += ((yy2 < m) and ((m-yy2)%2))*h;
	ax += (n - h)*(m%2);

	printf("%d\n", (ax+1)/2);

	return 0;
}
