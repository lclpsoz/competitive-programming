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
int mat[22][22][22];

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

ll sum (vector<int> &st, vector<int> &en) {
	for (int i = 0; i < 3; i++)
		if (st[i] > en[i]) return - 1e18;
	return
		mat[en[0]][en[1]][en[2]]
		- mat[st[0]-1][en[1]][en[2]] - mat[en[0]][st[1]-1][en[2]] - mat[en[0]][en[1]][st[2]-1]
		+ mat[st[0]-1][st[1]-1][en[2]] + mat[st[0]-1][en[1]][st[2]-1] + mat[en[0]][st[1]-1][st[2]-1]
		- mat[st[0]-1][st[1]-1][st[2]-1];
}

ll solve () {
	ll ans = - 1e18;
	vector<int> v1 = {1, 1, 1}, v2 = {1, 1, 1};
	do {
		v2 = v1;
		do {
			ans = max (ans, sum (v1, v2));
// 			for (int x : v1)
// 				printf ("%d ", x);
// 			putchar ('\n');
// 			for (int x : v2)
// 				printf ("%d ", x);
// 			putchar ('\n');
// 			printf ("%lld %lld\n", ans, sum (v1, v2));
		} while (nxt (v2));
	} while (nxt (v1));
			
	return ans;
}

int main () {
	scanf ("%d", &t);
	while (t--) {
		memset (mat, 0, sizeof mat);
		scanf ("%d %d %d", &a, &b, &c);
		for (int i = 1; i <= a; i++)
			for (int j = 1; j <= b; j++)
				for (int k = 1; k <= c; k++) {
					scanf ("%d", &mat[i][j][k]);
					mat[i][j][k] =
						mat[i][j][k]
						+ mat[i-1][j][k] + mat[i][j-1][k] + mat[i][j][k-1]
						- mat[i-1][j-1][k] - mat[i-1][j][k-1] - mat[i][j-1][k-1]
						+ mat[i-1][j-1][k-1];
// 					printf ("%d ", mat[i][j][k]);
				}
// 		putchar ('\n');
		printf ("%lld\n", solve ());
	}

	return 0;
}
