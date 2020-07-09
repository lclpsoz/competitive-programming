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

const int N = 5200 + 10;

int mat[N][N];
int pref[N][N];
bitset<4> conv[16] = {0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf};


int qry (int x, int y, int a, int b) {
	return pref[a][b] - pref[a][y] - pref[x][b] + pref[x][y];
}

int main () {
// 	int maxi = -1;
// 	for (int i = 4; i <= 5200; i++) {
// 		int now = 2;
// 		for (int j = 2; j < i; j++)
// 			if (i%j == 0)
// 				++now;
// 		if (now > maxi) {
// 			maxi = now;
// 			printf ("%d: %d\n", i, maxi);
// 			for (int j = 2; j < i; j++)
// 				if (i%j == 0)
// 					printf ("%d ", j);
// 			putchar ('\n');
// 		}
// 	}
	int n;
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < n/4; j++) {
			char c;
			scanf (" %c", &c);
			int p;
			if (c == 'A')
				p = 10;
			else if (c == 'B')
				p = 11;
			else if (c == 'C')
				p = 12;
			else if (c == 'D')
				p = 13;
			else if (c == 'E')
				p = 14;
			else if (c == 'F')
				p = 15;
			else
				p = c-'0';
			for (int k = 0; k < 4; k++)
				mat[i][1 + k + 4*j] = conv[p][3-k];
		}
		
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
// 			printf ("%d%c", mat[i][j], " \n"[j==n]);
			pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + mat[i][j];
		}
		
// 	for (int i = 1; i <= n; i++)
// 		for (int j = 1; j <= n; j++)
// 			printf ("%2d%c", pref[i][j], " \n"[j==n]);

	int ans = 1;
	for (int x = 2; x <= n; x++)
		if (n%x == 0) {
			bool yes = true;
			for (int i = 0; i < n and yes; i+=x)
				for (int j = 0; j < n and yes; j+=x) {
					int now = qry (i, j, i+x, j+x);
// 					printf ("%d %d %d %d: ", i, j, i+x, j+x);
// 					printf ("%d\n", now);
					if (now > 0 and now < x*x)
						yes = false;
				}
			if (yes)
				ans = x;
		}
		
	printf ("%d\n", ans);

	return 0;
}
