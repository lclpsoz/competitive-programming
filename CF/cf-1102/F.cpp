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

const int M = 1e4+10, MSK = 1<<16 + 1;

int n, m;
int mat[20][M];
int adj[20][20];
int jump[20][20];

int dp[18][18][MSK];

int solve (int v, int msk, int st) {
	if (msk+1 == (1<<n))
		return jump[v][st];
	int &ret = dp[v][st][msk];
	if (ret != -1) return ret;
	for (int i = 0; i < n; i++) {
		if (((1<<i)&msk) == 0) {
			int slv = solve (i, msk | (1<<i), st);
			ret = max (ret,
					   min (slv, adj[v][i]));
		}
	}
	
	return ret;
}
int main () {
	memset (dp, -1, sizeof dp);
	scanf ("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf ("%d", &mat[i][j]);
		
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			int k = 2e9;
			for (int l = 0; l < m; l++)
				k = min (k, abs (mat[i][l] - mat[j][l]));
			adj[i][j] = k;
		}
		
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int k = 2e9;
			for (int l = 0; l < m-1; l++)
				k = min (k, abs (mat[i][l] - mat[j][l+1]));
			jump[i][j] = k;
		}
	
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max (ans, solve (i, 1<<i, i));
	printf ("%d\n", ans);
	
	return 0;
}