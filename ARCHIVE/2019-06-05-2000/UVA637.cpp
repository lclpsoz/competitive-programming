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

int n;

int main () {
	while (scanf ("%d", &n), n) {
		printf ("Printing order for %d pages:\n", n);
		if (n > 1) {
			int qnt = (n-1)/4 + 1;
			int go = 1, back = qnt*4;
			for (int i = 1; i <= qnt ; i++) {
				printf ("Sheet %d, front: ", i);
				if (back > n)
					printf ("Blank, ");
				else
					printf ("%d, ", back);
				--back;
				printf ("%d\n", go++);
				
				printf ("Sheet %d, back : ", i);
				printf ("%d, ", go++);
				if (back > n)
					printf ("Blank\n");
				else
					printf ("%d\n", back);
				back--;
			}
		} else
			printf ("Sheet 1, front: Blank, 1\n");
	}

	return 0;
}
