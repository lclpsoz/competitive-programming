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

const int N = 2e6+100;

int n;
int arr[N];

ll solve (int p, int lst) {
	if (n > lst)
		return 
	else
		return arr[lvl];
}

int main () {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf ("%d", &arr[i]);
	sort (arr+1, arr+n+1, greater<int>());
	
	printf ("%lld\n", solve (1, 1));

	return 0;
}
