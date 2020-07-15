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

ld dist(ld x, ld y) {
	return sqrt(x*x + y*y);
}

int main () {
	int n, k, xf, yf;
	scanf("%d %d %d %d", &n, &k, &xf, &yf);
	int x, y;
	x = y = 0;
	if(cmp(dist((ld)xf, (ld)yf), k) == 1) {
		printf("Trap 1\n");
	} else {
		for(int i = 1; i <= n; i++) {
			char c;
			scanf(" %c", &c);
			switch(c) {
				case 'C':
					x += 1;
					break;
				case 'B':
					x -= 1;
					break;
				case 'D':
					y += 1;
					break;
				case 'E':
					y -= 1;
					break;
			}
			// printf("(%d, %d) %Lf\n", x, y, dist(xf-x, yf-y));
			if(cmp(dist(xf-x, yf-y), k) == 1) {
				printf("Trap %d\n", i);
				exit(0);
			}
		}
		if(x == xf and y == yf)
			printf("Sucesso\n");
		else
			printf("Trap %d\n", n);
	}

	return 0;
}
