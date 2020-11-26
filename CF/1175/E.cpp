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
int sparse[N][30];

int main () {
	memset (segsRight, -1, sizeof segsRight);
	int n, m;
	scanf ("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int l, r;
		scanf ("%d %d", &l, &r);
		segsRight[l+1] = max (segsRight[l+1], r);
	}
	int nowRight = -1, mxR = -1;
	nowRight = -1;
	for (int i = 0; i < N; i++) {
		if (segsRight[i] != -1 and segsRight[i] > nowRight)
			nowRight = segsRight[i];
		if (i > nowRight)
			nowRight = -1;
		mostRLeft[i] = nowRight;
	}

	for (int i = 0; i < N; i++)
		sparse[i][0] = mostRLeft[i];
	
	for (int i = 1; i < 20; i++)
		for (int j = 0; j < N; j++) {
			if (sparse[j][i-1] != -1) {
				if (sparse[sparse[j][i-1]+1][i-1] == sparse[j][i-1])
					sparse[j][i] = -1;
				else
					sparse[j][i] = sparse[sparse[j][i-1]+1][i-1];
			}
			else
				sparse[j][i] = -1;
		}
	
	// for (int j = 0; j <= 20; j++)
	// 	printf ("%3d%c", j, " \n"[j==20]);
	// for (int i = 0; i < 5; i++)
	// 	for (int j = 0; j <= 20; j++)
	// 		printf ("%3d%c", sparse[j][i], " \n"[j==20]);

	pref0[0] = mostRLeft[0] == -1;
	for (int i = 1; i < N; i++) 
		pref0[i] += pref0[i-1] + (mostRLeft[i] == -1);

	// for (int i = 0; i <= 22; i ++)
	// 	printf ("%2d: rl = %2d, pref0 = %2d\n", i,  mostRLeft[i], pref0[i]);
	while (m--) {
		int l, r;
		scanf ("%d %d", &l, &r);
		if (pref0[r] - pref0[l]) {
			printf ("-1\n");
		} else {
			int ans = 0;

			int val = l+1;
			do {
				// printf ("  val = %d\n", val);
				for (int i = 0; i < 20; i++)
					if (sparse[val][i+1] == -1 or sparse[val][i+1] >= r) {
						val = sparse[val][i]+1;
						ans += (1<<i);
						break;
					}
				// printf ("  val(out) = %d\n", val);
			} while (val <= r);

			printf ("%d\n", ans);
		}
	}

	return 0;
}
