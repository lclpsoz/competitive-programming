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

const int N = 110, M = 550;

int mat[N][N];
bool aux[M];

void grundy (int x, int y) {
  memset (aux, false, sizeof (aux));
  for (int i = 0; i < x; i++)
    if (mat[i][y] != -1)
      aux[mat[i][y]] = true; 
  for (int i = 0; i < y; i++)
    if (mat[x][i] != -1)
      aux[mat[x][i]] = true; 
  for (int i = x-1, j = y-1; i > 0 && j > 0; i--, j--)
    if (mat[i][j] != -1)
      aux[mat[i][j]] = true;
  for (int i = 0; i < M; i++)
    if (!aux[i]) {
      mat[x][y] = i;
      return;
    }
}

int main () {
  //memset (mat, -1, sizeof (mat));
  for (int i = 0; i < N; i++)
    mat[i][i] = mat[i][0] = mat[0][i] = -1;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      if (mat[i][j] != -1)
	grundy (i, j);

  /*printf ("  |");
  for (int i = 0; i < 30; i++)
    printf ("%2d|", i);
  putchar ('\n');
  for (int i = 0; i < 30; i++) {
    printf ("%2d|", i);
    for (int j = 0; j < 30; j++)
      printf ("%*d|", 2, mat[i][j]);
    putchar ('\n');
  }
  putchar ('\n');
  */

  int ans = 0;
  int n, x, y;
  scanf ("%d", &n);
  while (n--) {
    scanf ("%d %d", &x, &y);
    if (x == y) {
      printf ("Y\n");
      return 0;
    }
    ans ^= mat[x][y];
  }
  printf ("%s\n", ans == 0 ? "N" : "Y");
  
  
  return 0;
}
