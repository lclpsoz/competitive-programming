#include <bits/stdc++.h>
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

int n, r;
int u, v, d;
int mat[102][102];

int main () {
  while (scanf ("%d %d", &n, &r), n || r) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
	if (i == j)
	  mat[i][j] = 0;
	else
	  mat[i][j] = 1e9;
      }
    while (r--) {
      scanf ("%d %d %d", &u, &v, &d);
      mat[u][v] = mat[v][u] = min (mat[u][v], d);
    }

    for (int k = 1; k <= n; k++)
      for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	  mat[i][j] = min (mat[i][j], mat[i][k] + mat[k][j]);

    ll mini = 2e9;
    for (int i = 1; i <= n; i++) {
      ll dd = 0;
      for (int j = 1; j <= n; j++)
	dd += mat[i][j];
      mini = min (dd, mini);
    }
    for (int i = 1; i <= n; i++) {
      ll dd = 0;
      for (int j = 1; j <= n; j++)
	dd += mat[i][j];
      if (dd == mini)
	printf ("%d ", i);
    }
    putchar ('\n');
  }
  
  return 0;
}
