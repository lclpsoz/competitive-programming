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

const int N = 105;

int n, m;
char pres, mat[N][N];
set<char> ans;
int adj[][2] = {	{1, 0},
					{-1, 0},
					{0, 1},
					{0, -1}		};
			
int main () {
	scanf ("%d %d %c", &n, &m, &pres);
	ans.insert (pres);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf (" %c", &mat[i][j]);
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (mat[i][j] == pres)
				for (int k = 0; k < 4; k++) {
					char c = mat[i+adj[k][0]][j+adj[k][1]];
					if (c != '.' and c != '\0')
						ans.insert (c);
				}
	
	printf ("%d\n", len (ans)-1);
	

	return 0;
}
