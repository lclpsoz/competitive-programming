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

int n, a, d, h;
int mat[22][5];

bool func () {
  int x, y, z;
  int i = 1;
  int lim = 1 << n;
  while (i < lim) {
    if (__builtin_popcount (i) == 1) {
      ++i;
      continue;
    }
    x = y = z = 0;
    for (int j = 1, k = 0; j <= i; j<<=1, ++k) {
      if (i & j) {
	x += mat[k][0];
	y += mat[k][1];
	z += mat[k][2];
      }
    }
    //printf ("%d: %d %d %d\n", i, x, y, z);
    if (x == a && y == d && z == h)
      return true;
    ++i;
  }
    return false;
}

int main () {
  int x, y, z;
  cin >> n >> a >> d >> h;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 3; j++)
      scanf ("%d", &mat[i][j]);

  printf ("%s\n", func () ? "Y" : "N");
  
  return 0;
}
