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

int n, m;
queue<pii> q;
int ans = 0;

int main () {
	scanf ("%d %d", &n ,&m);
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		q.push ({x, i+1});
	}
	
	while (len (q) > 1) {
		pii now = q.front();
		q.pop();
		now.x -= m;
		if (now.x > 0)
			q.push (now);
	}
	printf ("%d\n", q.front().y);

	return 0;
}
