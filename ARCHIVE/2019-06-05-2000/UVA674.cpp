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

vector<int> coins = {50, 25, 10, 5, 1};
ll ans[8000];

int main () {
	ans[0] = 1;
	for (int c : coins)
		for (int i = c; i <= 7489; i++)
			ans[i] += ans[i-c];
	
	int x;
	while (scanf ("%d", &x) != EOF)
		printf ("%lld\n", ans[x]);

	return 0;
}
