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

const int N = 1e5+10;

int n, p;
string str;
int a[N], sum;

int rightLeft (int l, int r) {
	int op = 0, ax = sum;
	for (;ax and p <= r; p++) {
		op += a[p];
		ax -= a[p];
		if (ax == 0 or p == r)
			break;
		++op;
	}
	
	for (;ax and p >= l; p++) {
		op += a[p];
		ax -= a[p];
		if (ax == 0 or p == l)
			break;
		++op;
	}
	
	return op;
		
}

int leftRight (int l, int r) {
}

int main () {
	cin.tie (0);
	ios::sync_with_stdio (false);
	cin >> n >> p >> str;
	
	for (int i = 0; i < n/2; i++) {
		a[i] = min (abs (str[i]-str[n-i-1]), 26 - abs (str[i]-str[n-i-1]));
		sum += a[i];
	}
	printf ("%d\n", sum);
	if (!sum) {
		printf ("%d\n", sum);
		
	}
	--p; // 0-index
	
	
	return 0;
}
