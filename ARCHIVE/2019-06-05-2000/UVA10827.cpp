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

const int N = 3*75 + 10;

int t, n;
int mat[N][N];
deque<pii> dq;

int sum (int l, int r, int y) {
// 	printf ("sum: %d %d\n", mat[r][y], mat[l-1][y]);
	return mat[y][r] - mat[y][l-1];
}

int solve () {
	int ret = - 2e9;
	for (int i = 1; i <= 3*n; i++)
		for (int j = i; j <= 3*n and (j-i+1) <= n; j++) {
			int pref = 0;
			dq.push_back ({0, 0});
			for (int k = 1; k <= 3*n; k++) {
				pref += sum (i, j, k);
				if ((k-dq.front().x) > n)
					dq.pop_front();
				ret = max (ret, pref-dq.front().y);
				while (!dq.empty() and dq.back().y >= pref)
					dq.pop_back ();
				dq.push_back ({k, pref});
			}
			while (!dq.empty()) dq.pop_back ();
// 			int acu = 0;
// 			for (int st = 1; st <= 3*n; st++) {
// 				acu = 0;
// 				for (int k = st; k <= 3*n and (k-st+1) <= n; k++) {
// 					int x = sum (i, j, k);
// 					if (x > acu+x)
// 						acu = x;
// 					else
// 						acu += x;
// 					ret = max (acu, ret);
// // 					printf ("%d %d %d: %d\n", i, j, k, acu);
// 				}
// 			}
		}
		
	return ret;
}

int main () {
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d", &n);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				int x;
				scanf ("%d", &x);
				for (int k = 0; k < 3; k++)
					for (int l = 0; l < 3; l++)
						mat[i + k*n][j + l*n] = x;
			}
		
		for (int i = 1; i <= 3*n; i++)
			for (int j = 1; j <= 3*n; j++) {
				mat[i][j] += mat[i][j-1];
// 				printf ("%d%c", mat[i][j], " \n"[j==3*n]);
			}
		
		printf ("%d\n", solve ());
	}

	return 0;
}
