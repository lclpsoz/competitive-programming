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
ll k;
deque<int> dq;

int main () {
	scanf ("%d %lld", &n, &k);
	while (n--) {
		int x;
		scanf ("%d", &x);
		dq.push_back (x);
	}
	sort (dq.begin(), dq.end());

	int qntMn, qntMx;
	qntMn = qntMx = 0;
	int mn = dq.front();
	int mx = dq.back();
	if (mn == mx)
		printf ("0\n");
	else {
		while (k and mx > mn) {
			while (!dq.empty() and dq.front() == mn) dq.pop_front (), qntMn++;
			while (!dq.empty() and dq.back() == mx) dq.pop_back (), qntMx++;

			if (qntMn < qntMx) {
				int dif;
				if (!dq.empty())
					dif = dq.front() - mn;
				else
					dif = mx - mn;
				if (k >= dif*1LL*qntMn) {
					if (!dq.empty())
						mn = dq.front();
					else
						mn = mx;
					k -= dif*1LL*qntMn;
				} else {
					mn += k/qntMn;
					k = 0;
				}
			} else {
				int dif;
				if (!dq.empty())
					dif = mx - dq.back();
				else
					dif = mx - mn;
				if (k >= dif*1LL*qntMx) {
					if (!dq.empty())
						mx = dq.back();
					else
						mx = mn;
					k -= dif*1LL*qntMx;
				} else {
					mx -= k/qntMx;
					k = 0;
				}
			}
			// printf ("mx = %d, mn = %d, qMx = %d, qMn = %d\n", mx, mn, qntMx, qntMn);
		}
		printf ("%d\n", mx-mn);
	}

	return 0;
}
