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

const int N = 2e5 + 10;

int mat[5][N];
bool pos[5][N][2];

int main () {
	int q;
	scanf ("%d", &q);
	while (q--) {
		int n;
		scanf ("%d", &n);
		for (int i = 0; i <= n; i++)
			for (int j = 0; j < 2; j++)
				for (int k = 0; k < 2; k++)
					pos[j][i][k] = false;
		for (int i = 1; i <= n; i++) {
			char c;
			scanf (" %c", &c);
			if (c <= '2') mat[0][i] = 1;
			else mat[0][i] = 2;
		}
		for (int i = 1; i <= n; i++) {
			char c;
			scanf (" %c", &c);
			if (c <= '2') mat[1][i] = 1;
			else mat[1][i] = 2;
		}
		queue<pair<pii, int>> q;
		q.push ({{0, 1}, 0}); // FORWARD
		while (!q.empty()) {
			int x = q.front().x.x;
			int y = q.front().x.y;
			int typ = q.front().y;
			printf ("%d %d %d: %d\n", x, y, typ, mat[x][y]);
			q.pop();
			printf ("|%d\n", pos[0][5][0]);
			if (pos[x][y][typ]) continue;
			printf ("here!\n");
			pos[x][y][typ] = true;
			if (typ == 0 and mat[x][y] == 1)
				q.push ({{x, y+1}, 0});
			if (mat[x][y] == 2) {
				if (typ == 0)
					q.push ({{!x, y}, x+1}); // 1: DOWN and 2: UP
				else
					q.push ({{x, y+1}, 0});
			}
		}
		printf ("%s\n", pos[1][n+1][0] ? "YES" : "NO");
	}

	return 0;
}
