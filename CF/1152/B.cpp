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
vector<int> ans;

int main () {
	scanf ("%d", &n);
	
// 	for (int nn = 1; nn <= 1000000; nn++) {
// 		printf ("nn: %d\n", nn);
// 		n = nn;
	while (true) {
		int ax = n;
		int p = 0;
		int lf = 0;
		while (ax) {
			if (ax%2 == 0) p = lf;
			ax /= 2;
			lf++;
		}
// 			printf ("%d\n", n);
		if ((1<<(lf))-1 == n) // END
			break;
		
		if ((n&1) == 0) {
			ans.push_back (0);
			++n;
		} else {
			int v = (1<<(p+1))-1;
			ans.push_back (p+1);
			n ^= v;
			++n;
		}
	}
	printf ("%d\n", len (ans)*2);
	for (int i = 0; i < len (ans); i++)
		printf ("%d ", ans[i]);
	putchar ('\n');
// 		if (len (ans)*2 > 40) return 0;
// 		ans.clear();
// 	}

	return 0;
}
