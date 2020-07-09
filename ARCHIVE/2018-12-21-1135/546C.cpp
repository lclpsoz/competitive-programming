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

int n, k;
queue<int> one, two;

int main () {
	scanf ("%d", &n);
	scanf ("%d", &k);
	for (int i = 0; i < k; i++) {
		int x;
		scanf ("%d", &x);
		one.push (x);
	}
	scanf ("%d", &k);
	for (int i = 0; i < k; i++) {
		int x;
		scanf ("%d", &x);
		two.push (x);
	}
	
	int qnt = 0;
	while (!one.empty() and !two.empty() and qnt < 1e6) {
		if (one.front() > two.front()) {
			one.push (two.front());
			one.push (one.front());
		} else {
			two.push (one.front());
			two.push (two.front());
		}
		one.pop(); two.pop();
		++qnt;
	}
	
	if (one.empty())
		printf ("%d 2\n", qnt);
	else if (two.empty())
		printf ("%d 1\n", qnt);
	else
		printf ("-1\n");

	return 0;
}
