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

int t, a, b, c;
ll mat[22][22][22];

bool nxt (vector<int> &v) {
	v[2]++;
	if (v[2] > c) {
		v[2] = 1;
		v[1]++;
	}
	if (v[1] > b) {
		v[1] = 1;
		v[0]++;
	}
	if (v[0] > a)
		return false;
	return true;
}

ll sum (int stX, int stY, int x, int y, int z) {
	return
		mat[x][y][z] - mat[stX-1][y][z] - mat[x][stY-1][z] + mat[stX-1][stY-1][z];
}

ll solve () {
	ll ans = - 1e18;
	for (int i = 1; i <= a; i++)
		for (int j = 1; j <= b; j++)
			for (int i2 = i; i2 <= a; i2++)
				for (int j2 = j; j2 <= b; j2++) {
					ll acu = - 1e18;
					for (int k = 1; k <= c; k++) {
						ll now = sum (i, j, i2, j2, k);
						if (now > acu + now)
							acu = now;
						else
							acu += now;
						ans = max (ans, acu);
					}
				}
			
	return ans;
}

int main () {
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d %d %d", &a, &b, &c);
		for (int i = 1; i <= a; i++)
			for (int j = 1; j <= b; j++)
				for (int k = 1; k <= c; k++)
					scanf ("%lld", &mat[i][j][k]);
				
		for (int k = 1; k <= c; k++)
			for (int i = 1; i <= a; i++)
				for (int j = 1; j <= b; j++)
					mat[i][j][k] += mat[i-1][j][k] + mat[i][j-1][k] - mat[i-1][j-1][k];
			
		printf ("%lld\n", solve ());
		if (t) putchar ('\n');
	}

	return 0;
}
