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
int cmp(ld x, ld y = 0, ld tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
int mod (ll x, ll m = MOD) {
  return ((x%m) + m)%m;
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 205;

int h, l;
int mat[N][N];
int adj[][2] = {{0, 1},
		{1, 0},
		{0, -1},
		{-1, 0}};

int dfs (int x, int y, int v) {
  if (mat[x][y] != v)
    return 0;
  mat[x][y] = -2;
  int r = 1;
  for (int i = 0; i < 4; i++)
    r += dfs (x+adj[i][0], y+adj[i][1], v);
  return r;
}

int main () {
  memset (mat, -1, sizeof (mat));
  scanf ("%d %d", &h, &l);
  for (int i = 1; i <= h; i++)
    for (int j = 1; j <= l; j++)
      scanf ("%d", &mat[i][j]);
  int ans = 1e9;
  for (int i = 1; i <= h; i++)
    for (int j = 1; j <= l; j++)
      if (mat[i][j] != -2)
	ans = min (ans, dfs (i, j, mat[i][j]));

  printf ("%d\n", ans);

  return 0;
}
