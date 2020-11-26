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

pii w1, w2;
pii a1, a2;
pii b1, b2;

int main () {
	cin >> w1.x >> w1.y >> w2.x >> w2.y;
	cin >> a1.x >> a1.y >> a2.x >> a2.y;
	cin >> b1.x >> b1.y >> b2.x >> b2.y;


	for(int j = 2*w1.y; j <= 2*w2.y; j++) {
		double x = w1.x, y = j/2.0;
		// cout << x << ' ' << y << '\n';
		if(	((cmp(x, a1.x) == -1 or cmp(x, a2.x) == 1) or
			(cmp(y, a1.y) == -1 or cmp(y, a2.y) == 1)) and
			((cmp(x, b1.x) == -1 or cmp(x, b2.x) == 1) or
			(cmp(y, b1.y) == -1 or cmp(y, b2.y) == 1))) {
				printf("YES\n");
				exit(0);
			}
	}

	for(int j = 2*w1.y; j <= 2*w2.y; j++) {
		double x = w2.x, y = j/2.0;
		// cout << x << ' ' << y << '\n';
		if(	((cmp(x, a1.x) == -1 or cmp(x, a2.x) == 1) or
			(cmp(y, a1.y) == -1 or cmp(y, a2.y) == 1)) and
			((cmp(x, b1.x) == -1 or cmp(x, b2.x) == 1) or
			(cmp(y, b1.y) == -1 or cmp(y, b2.y) == 1))) {
				printf("YES\n");
				exit(0);
			}
	}

	for(int i = 2*w1.x; i <= 2*w2.x; i++) {
		double x = i/2.0, y = w1.y;
		// cout << x << ' ' << y << '\n';
		if(	((cmp(x, a1.x) == -1 or cmp(x, a2.x) == 1) or
			(cmp(y, a1.y) == -1 or cmp(y, a2.y) == 1)) and
			((cmp(x, b1.x) == -1 or cmp(x, b2.x) == 1) or
			(cmp(y, b1.y) == -1 or cmp(y, b2.y) == 1))) {
				printf("YES\n");
				exit(0);
			}
	}
	for(int i = 2*w1.x; i <= 2*w2.x; i++) {
		double x = i/2.0, y = w2.y;
		// cout << x << ' ' << y << '\n';
		if(	((cmp(x, a1.x) == -1 or cmp(x, a2.x) == 1) or
			(cmp(y, a1.y) == -1 or cmp(y, a2.y) == 1)) and
			((cmp(x, b1.x) == -1 or cmp(x, b2.x) == 1) or
			(cmp(y, b1.y) == -1 or cmp(y, b2.y) == 1))) {
				printf("YES\n");
				exit(0);
			}
	}
	printf("NO\n");

	return 0;
}
