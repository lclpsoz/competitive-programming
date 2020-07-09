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

char opt[] = {'A', 'G', 'C', 'T'};
int n, m;
int cols[300100][5][5];

int main () {
	scanf ("%d %d", &n, &m);
	vector<vector<char>> mat(n, vector<char>(m));
		
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf (" %c", &mat[i][j]);

	int valBest = 1e9;
	pii best = {-1, -1};
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			if (i == j) continue;
			int valNow = cols[0][i][j]; // First column
			pii other = {-1, 0};
			for (int v = 0; v < 4; v++)
				if (v != i and v != j and v != other.x) {
					if (other.x == -1)
						other.x = v;
					else
						other.y = v;
				}
			for (int col = 1; col < m; col++)
				if (col&1)
					valNow += min (cols[col][other.x][other.y],
								   cols[col][other.y][other.x]);
				else
					valNow += min (cols[col][i][j],
								   cols[col][j][i]);
			if (valNow <= valBest) {
				valBest = valNow;
				best = {i, j};
			}
// 			printf ("%d %d other: %d %d| valNow: %d\n", i, j, other.x, other.y, valNow);
		}
		
	pii other = {-1, -1};
	for (int v = 0; v < 4; v++)
		if (v != best.x and v != best.y and v != other.x) {
			if (other.x == -1)
				other.x = v;
			else
				other.y = v;
		}
// 	printf ("%d %d %d %d\n", best.x, best.y, other.x, other.y);
	for (int col = 0; col < m; col++) {
		pii now;
		now = (col%2 == 0 ? best : other);
		if (cols[col][now.x][now.y] > cols[col][now.y][now.x])
			now = {now.y, now.x};
// 		printf ("%d %d: %d %d\n", now.x, now.y, cols[col][now.x][now.y], cols[col][now.y][now.x]);
		for (int lin = 0; lin < n; lin++)
			mat[lin][col] = (lin%2 == 0 ? opt[now.x] : opt[now.y]);
	}
	
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			putchar (mat[i][j]);
		putchar ('\n');
	}
	
	return 0;
}
