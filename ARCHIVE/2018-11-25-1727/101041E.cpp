#include <stdio.h>
#include <vector>
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

const int MOD = 1e9+7;
inline int mod (ll x, int m = MOD) {
  return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

using row = vector<int>;
using matrix = vector<row>;

matrix initMatrix (int lin, int col) {
  return matrix(lin, row(col));
}

matrix operator* (matrix &a, matrix &b) {
  //assert (len (a) && len (a[0]) == len (b));
  int lin = len (a[0]);
  int col = len (b);
  matrix ret = initMatrix (lin, col);

  for (int i = 0; i < lin; i++)
    for (int j = 0; j < col; j++)
      for (int k = 0; k < lin; k++)
	ret[i][j] = mod ((ll)ret[i][j] + mod (a[i][k]*1LL*b[k][j]));

  return ret;
}

matrix fstExp (matrix b, int p) {
  matrix aux = initMatrix (len (b), len (b));
  for (int i = 0; i < len (aux); i++)
    aux[i][i] = 1;
  while (p) {
    if (p&1)
      aux = aux * b;
    p >>= 1;
    b = b*b;
    /*
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++)
	printf ("%d ", b[i][j]);
      putchar ('\n');
    }
    */
  }

  return aux;
}

int main () {
  matrix base = initMatrix (2, 2);
  base[0][1] = 1;
  base[1][0] = 1;
  base[1][1] = 1;
  int t;
  scanf ("%d", &t);
  while (t--) {
    int n;
    scanf ("%d", &n);
    matrix ans = fstExp (base, n+1);
    printf ("%d\n", ans[0][0]);
  }

  return 0;
}
