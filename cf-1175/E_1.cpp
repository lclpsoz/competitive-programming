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

const int N = 5e5 + 10;

int mostRRight[N], mostRLeft[N];
int segsRight[N];
int pref0[N], prefRight[N], prefLeft[N];

int main () {
	memset (segsRight, -1, sizeof segsRight);
	int n, m;
	scanf ("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int l, r;
		scanf ("%d %d", &l, &r);
		segsRight[l+1] = max (segsRight[l+1], r);
	}
	int nowRight = -1, nowRightL = -1, mxR = -1;
	for (int i = 0; i < N; i++) {
		if (segsRight[i] != -1 and segsRight[i] > mxR) {
			mxR = segsRight[i];
		}
		// if (i < 20)
		// 	printf ("i = %d: mxR = %d\n", i, mxR);
		if (i > nowRight) {
			if (mxR < i)
				nowRight = -1;
			else
				nowRight = mxR;
		}
		mostRRight[i] = nowRight;
	}

	nowRight = -1;
	for (int i = 0; i < N; i++) {
		if (segsRight[i] != -1 and segsRight[i] > nowRight)
			nowRight = segsRight[i];
		if (i > nowRight)
			nowRight = -1;
		mostRLeft[i] = nowRight;
	}


	pref0[0] = mostRRight[0] == -1;
	for (int i = 1; i < N; i++)
		pref0[i] += pref0[i-1] + (mostRRight[i] == -1);

	prefRight[0] = mostRRight[0] != -1;
	for (int i = 1; i < N; i++)
		prefRight[i] = prefRight[i-1] + (mostRRight[i-1] != mostRRight[i]);
	
	prefLeft[0] = mostRLeft[0] != -1;
	for (int i = 1; i < N; i++)
		prefLeft[i] = prefLeft[i-1] + (mostRLeft[i-1] != mostRLeft[i]);

	for (int i = 0; i <= 22; i ++)
		printf ("%2d: rr = %2d, rl = %2d, pref0 = %2d, prefR = %2d, prefL = %2d\n", i, mostRRight[i], mostRLeft[i], pref0[i], prefRight[i], prefLeft[i]);
	while (m--) {
		int l, r;
		scanf ("%d %d", &l, &r);
		if (pref0[r] - pref0[l]) {
			printf ("-1\n");
		} else {
			printf ("%d\n", prefRight[r]-prefLeft[l+1]+1);
		}
	}

	return 0;
}
