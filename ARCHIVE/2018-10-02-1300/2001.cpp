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

const int MOD = 303700049;
inline int mod (ll x, int m = MOD) {
  return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

using row = vector<int>;
using matrix = vector<row>;

matrix initMat (int nRow, int nCol) {
  return matrix (nRow, row (nCol));
}

matrix operator* (matrix &a, matrix &b) {
  assert (len(a) && len (a[0]) == len(b));
  int nRow = len (b);
  int nCol = min (len (b[0]), len (a));
  matrix ret = initMat (nRow, nCol);
  for (int i = 0; i < nRow; i++)
    for (int j = 0; j < nCol; j++)
      for (int k = 0; k < nRow; k++)
	ret[i][j] = mod (ret[i][j] + a[i][k] * 1LL * b[k][j]);

  return ret;
}

void operator*= (matrix &a, matrix &b) {
  a = a*b;
}

matrix matPowmod (matrix &a, int p) {
  int nRow = len(a);
  int nCol = len(a[0]);
  matrix ret = initMat (nRow, nCol);
  for (int i = 0; i < min (nRow, nCol); i++)
    ret[i][i] = 1;
  while (p) {
    if (p&1) ret *= a;
    p >>= 1;
    a *= a;
  }

  return ret;
}

void prt (matrix &mat) {
  for (int i = 0; i < len (mat); i++) {
    for (int j = 0; j < len (mat[i]); j++)
      printf ("%d ", mat[i][j]);
    putchar ('\n');
  }
}

int main () {
  int n, k;
  while (scanf ("%d %d", &n, &k) != EOF) {
    matrix mat = initMat (n, n);
    for (int i = 1; i < n; i++)
      mat[i-1][i] = 1;
    for (int i = n-1; i >= 0; i--)
      mat[n-1][i] = n-i;
    matrix col = initMat (n, 1);
    for (int i = 0; i < n; i++)
      scanf ("%d", &col[i][0]);
    mat = matPowmod (mat, k-1);
    //prt (mat);
    col = mat*col;
    prt (col);
    // printf ("%d %d\n", col[1][0], mod (col[0][0]+col[1][0]-1));
  }
  
  return 0;
}
