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

int t, ang;
int ans[200];

int main () {
	memset (ans, -1, sizeof ans);
	for (int i = 3; i <= 1000; i++) {
		int sumAng = (i-2)*180;
		if (sumAng%i == 0) {
// 			printf ("%d ", i);
			ang = sumAng/i;
			if (ans[ang] == -1) ans[ang] = i;
			for (int j = 3; j < i; j++)  {
				int sumNow = (j-2)*180;
				int sum2 = sumNow - (j-2)*ang;
				if (sum2 % 2 == 0) {
					sum2 /= 2;
					if (ans[sum2] == -1)
						ans[sum2] = i;
				}
			}
		}
		else {
//  			printf ("NO %d\n", i);
		}
	}
	
// 	for (int i = 1; i <= 180; i++)
// 		printf ("%d: %d\n", i, ans[i]);
	
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d", &ang);
		printf ("%d\n", ans[ang]);
	}

	return 0;
}