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

vector<pii> pos, neg;
int zero = -1, sumNeg = 0;

void solve (int p, int r) {
	if (p == len (neg)) return;

}

int main () {
	int n, r;
	scanf ("%d %d", &n, &r);
	while (n--) {
		int a, b;
		scanf ("%d %d", &a, &b);
		if (b == 0) zero = max (zero, a);
		else if (b > 0) pos.push_back ({a, b});
		else {
			neg.push_back ({a, b});
			sumNeg += b;
		}
	}
	sort (pos.begin(), pos.end());
	for (auto p : pos) {
		if (r < p.x) {
			printf ("NO\n");
			exit (0);
		} 
		r += p.y;
	}
	if (-sumNeg > r or zero > r) {
		printf ("NO\n");
		exit (0);
	}
	for (int k = 0; k < 1e5; k++) {
		int rr = r;
		// printf ("r = %d\n", r);
		int pos = -1;
		for (int i = 0; i < len (neg); i++) {
			if (neg[i].x > r) {
				pos = i;
				break;
			}
			r += neg[i].y;
		}
		if (pos == -1) {
			printf ("YES\n");
			exit (0);
		}
		if (pos == 0) {
			printf ("NO\n");
			exit (0);
		} else
			swap (neg[pos-1], neg[pos]);
		r = rr;
	}
	printf ("NO\n");



	return 0;
}
