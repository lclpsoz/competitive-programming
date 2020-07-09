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

int n, qnt;
ld down, st, pay;
ld inter[110];

int main () {
	while (scanf ("%d", &n), n >= 0) {
		for (int i = 0; i <= n; i++)
			inter[i] = -1000;
		assert (n > 0);
		scanf ("%Lf %Lf %d", &down, &st, &qnt);
		pay = st / n;
// 		printf ("n = %d\n", n);
		while (qnt--) {
			int month;
			ld x;
			scanf ("%d %Lf", &month, &x);
			inter[month] = 1 - x;
		}
		for (int i = 1; i <= n; i++)
			if (inter[i] < -1) inter[i] = inter[i-1];
			
		ld value = (st+down)*inter[0];
		ld debt = st;
// 		printf ("i: 0 (%Lf), debt = %Lf, value = %Lf\n", inter[0], debt, value);
		for (int i = 1; i <= n; i++) {
			if (cmp (value, debt) == 1) {
				printf ("0 months\n");
				break;
			}
			debt -= pay;
			value *= inter[i];
// 			printf ("i: %d (%Lf), debt = %Lf, value = %Lf\n", i, inter[i], debt, value);
			if (cmp (value, debt) == 1) {
				if (i == 1)
					printf ("1 month\n");
				else
					printf ("%d months\n", i);
				break;
			}
		}
	}

	return 0;
}
