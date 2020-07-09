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

const int N = 502;

int bit[N][N];

void add (int x, int y, int z, int w, int v) {
  int p;
  for (int i = x; i <= z; i++) {
    p = y;
    while (p < N) {
      bit[i][p] += v;
      p += p&-p;
    }
    p = w+1;
    while (p < N) {
      bit[i][p] -= v;
      p += p&-p;
    }
  }
}

int sum (int row, int p) {
  int r = 0;
  while (p > 0) {
    r += bit[row][p];
    p -= p&-p;
  }
  
  return r;
}

int main () {
  int q;
  char ch;
  int x, y, z, w, v;
  
  scanf ("%d", &q);
  while (q--) {
    scanf (" %c", &ch);
    if (ch == 'U') {
      scanf ("%d %d %d %d %d", &x, &y, &z, &w, &v);
      add (x, y, z, w, v);
    } else {
      scanf ("%d %d", &x, &y);
      printf ("%d\n", sum (x, y));
    }
  }
  
  return 0;
}
