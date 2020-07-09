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

const int N = 102, K = 1e5+10;

int n;
int a[N];
int dp[K];

bool solve (int k) {
	int &r = dp[k];
	if (r != -1) return r;
	for (int i = 1; i <= n; i++)
		if (k-a[i] >= 0 and !solve (k-a[i]))
			return r = 1;
	return r = 0;
}

int main () {
	memset (dp, -1, sizeof dp);
	int k;
	scanf ("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf ("%d", &a[i]);
	printf ("%s\n", solve (k) ? "First" : "Second");
	
	return 0;
}
