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

int qnt, q, n, x;
int mat[5][16][16];

int main () {
  scanf ("%d", &q);
  while (q--) {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
	scanf ("%d", &mat[0][i][j]);

    for (int i = 0; i < n; i++) {
      bool ativ = false;
      for (int j = 0; j < n; j++) {
	if (mat[0][i][j])
	  ativ = true;
	mat[1][i][j] = ativ;
      }
    }
    for (int i = 0; i < n; i++) {
      bool ativ = false;
      for (int j = n-1; j >= 0; j--) {
	if (mat[0][i][j])
	  ativ = true;
	mat[2][i][j] = ativ;
      }
    }
    for (int i = 0; i < n; i++) {
      bool ativ = false;
      for (int j = 0; j < n; j++) {
	if (mat[0][j][i])
	  ativ = true;
	mat[3][j][i] = ativ;
      }
    }
    for (int i = 0; i < n; i++) {
      bool ativ = false;
      for (int j = n-1; j >= 0; j--) {
	if (mat[0][j][i])
	  ativ = true;
	mat[4][j][i] = ativ;
      }
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
	if (mat[1][i][j] &&
	    mat[2][i][j] &&
	    mat[3][i][j] &&
	    mat[4][i][j])
	  ++qnt;
    
    printf ("%.2Lf\n", (ld)qnt/2);
    qnt = 0;
  }
  
  return 0;
}
