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

int n, r;
int a[1010], lights[1010];

void lightUp (int p) {
	if (p == -1) {
		printf ("-1\n");
		exit (0);
	}
	for (int i = max (0, p-r+1); i < min (n, p+r); i++)
		lights[i] = true;
}

bool check (int p) {
	if (p-r >= 0)
// 		printf("p: %d %d\n", p, a[p-r]);
	for (int i = p-r; i >= 0; i--)
		if (!lights[i]) return false;
	return true;
}

int main () {
	scanf ("%d %d", &n, &r);
	for (int i = 0; i < n; i++)
		scanf ("%d", &a[i]);
	
	int bef = -1, ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i]) {
// 			printf ("%d: %d|bef: %d\n", i, check (i), bef);
			if (!check (i)) {
				++ans;
				lightUp (bef);
			}
			bef = i;
		}
	}
	
// 	for (int i = 0; i < n; i++)
// 		printf ("%d", a[i]);
// 	putchar ('\n');
	
	for (int i = 0; i < n; i++)
		if (!lights[i]) {
			++ans;
			lightUp (bef);
			break;
		}
// 	for (int i = 0; i < n; i++)
// 		printf ("%d", a[i]);
// 	putchar ('\n');
	for (int i = 0; i < n; i++)
		if (!lights[i]) {
			printf ("-1\n");
			return 0;
		}
	printf ("%d\n", ans);

	return 0;
}
