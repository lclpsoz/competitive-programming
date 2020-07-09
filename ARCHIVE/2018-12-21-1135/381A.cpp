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
int a, b;
deque<int> dq;

int main () {
	scanf ("%d", &n);
	while (n--) {
		int x;
		scanf ("%d", &x);
		dq.push_back (x);
	}

	bool test = true;
	while (!dq.empty()) {
		if (test) {
			if (dq.front() > dq.back()) {
				a += dq.front();
				dq.pop_front();
			}
			else {
				a += dq.back();
				dq.pop_back();
			}
		} else {
			if (dq.front() > dq.back()) {
				b += dq.front();
				dq.pop_front();
			}
			else {
				b += dq.back();
				dq.pop_back();
			}
		}
		test = !test;
	}

	printf ("%d %d\n", a, b);

	return 0;
}
