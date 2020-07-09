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

const int N = 110;

int ans, mini = 110;
int a[N];

int main () {
	int n;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &a[i]);
		mini = min (mini, a[i]);
	}

	for (int j = 0; j < 1e5; j++)
		for (int i = 0; i < n; i++) {
			while (a[i] > mini)
				a[i] -= mini;
			mini = min (mini, a[i]);
		}
		
	for (int i = 0; i < n; i++)
		ans += a[i];
	printf ("%d\n", ans);
		

	return 0;
}
