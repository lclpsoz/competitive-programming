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

const int N = 1010;

int n, m;
int mat[N][N];
int maxR[N], maxC[N];
int rows[N][N], cols[N][N];
bool vis[N];

int main () {
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf ("%d", &mat[i][j]);

	for (int i = 1; i <= n; i++) {
		int mini = 1e9+ 100;
		for (int j = 1; j <= m; j++)
			mini = min (mini, mat[i][j]);

		queue<pii> q;
		for (int j = 1; j <= m; j++) {
			vis[j] = false;
			if (mat[i][j] == mini)
				q.push ({1, j});
		}

		int &maxi = maxR[i];
		maxi = -1;
		while (!q.empty()) {
			int v = q.front().x;
			int p = q.front().y;
			q.pop();
			if (p < 1 or p > m or vis[p]) continue;
			vis[p] = true;
			maxi = max (v, maxi);
			rows[i][p] = v;
			if (mat[i][p] > mat[i][p+1])
				q.push ({v-1, p+1});
			else if (mat[i][p] < mat[i][p+1])
				q.push ({v+1, p+1});
			else
				q.push ({v, p+1});
			if (mat[i][p] > mat[i][p-1])
				q.push ({v-1, p-1});
			else if (mat[i][p] < mat[i][p-1])
				q.push ({v+1, p-1});
			else
				q.push ({v, p-1});
		}
	}

	for (int j = 1; j <= m; j++) {
		int mini = 1e9+ 100;
		for (int i = 1; i <= n; i++)
			mini = min (mini, mat[i][j]);

		queue<pii> q;
		for (int i = 1; i <= n; i++) {
			vis[i] = false;
			if (mat[i][j] == mini)
				q.push ({1, i});
		}

		int &maxi = maxC[j];
		maxi = -1;
		while (!q.empty()) {
			int v = q.front().x;
			int p = q.front().y;
			q.pop();
			// printf ("j = %d, p = %d, v = %d\n", j, p, v);
			if (p < 1 or p > n or vis[p]) continue;
			// printf ("  j = %d, p = %d, v = %d\n", j, p, v);
			vis[p] = true;
			maxi = max (v, maxi);
			cols[p][j] = v;
			if (mat[p][j] > mat[p+1][j])
				q.push ({v-1, p+1});
			else if (mat[p][j] < mat[p+1][j])
				q.push ({v+1, p+1});
			else
				q.push ({v, p+1});

			if (mat[p][j] > mat[p-1][j])
				q.push ({v-1, p-1});	
			else if (mat[p][j] < mat[p-1][j])
				q.push ({v+1, p-1});
			else
				q.push ({v, p-1});
		}
	}
	// for (int i = 1; i <= n; i++)
	// 	for (int j = 1; j <= m; j++)
	// 		printf ("%d%c", cols[i][j], " \n"[j==m]);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			int maxi = max (rows[i][j], cols[i][j]);
			printf ("%d", max ((maxi - rows[i][j]) + maxR[i], (maxi - cols[i][j]) + maxC[j]));
			if (j == m)
				putchar ('\n');
			else
				putchar (' ');
		}

	
	return 0;
}
