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

ll mat[5][5][5], aux[5][5][5];

ll sum (int x, int y, int z) {
  ll r = 0;
  
  for (int i = -1; i <= 1; i++)
    for (int j = -1; j <= 1; j++)
      for (int k = -1; k <= 1; k++)
	r += mat[i+x][j+y][k+z];
  
  return r;
}

int main () {  
  int n, t;
  scanf ("%d", &t);
  while (t--) {
    scanf ("%d", &n);
    for (int i = 1; i <= 3; i++)
      for (int j = 1; j <= 3; j++)
	for (int k = 1; k <= 3; k++)
	  scanf ("%lld", &mat[i][j][k]);
    for (int q = 0; q < n; q++) {
      for (int i = 1; i <= 3; i++)
	for (int j = 1; j <= 3; j++)
	  for (int k = 1; k <= 3; k++)
	    aux[i][j][k] = sum (i, j, k);
      memcpy (mat, aux, sizeof aux);
    }
    for (int i = 1; i <= 3; i++)
      for (int j = 1; j <= 3; j++) {
	for (int k = 1; k <= 3; k++) {
	  printf ("%lld", mat[i][j][k]);
	  if (k < 3)
	    putchar (' ');
	}
	putchar ('\n');
      }
  }
  
  return 0;
}
