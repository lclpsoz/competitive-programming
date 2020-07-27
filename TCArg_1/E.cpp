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
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e5 + 10;

int n;
int a[N];

int main () {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	int l = 0, r = n+1;
	int ql,qr;
	ql = qr = 0;
	int tl = 0;
	int tr = 0;
	while(l < r-1) {
		if(tl <= tr) {
			++ql;
			tr -= tl;
			++l;
			tl = a[l];
		} else {
			++qr;
			tl -= tr;
			--r;
			tr = a[r];
		}
		// printf("l = %d, r = %d\n", l, r);
	}
	printf("%d %d\n", ql, qr);

	return 0;
}
