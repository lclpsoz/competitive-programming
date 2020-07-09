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

void add (int x, int _y, int v) {
  for (; x < N; x += x&-x)
    for (int y = _y; y < N; y += y&-y)
      bit[x][y] += v;
}

int sum (int x, int _y) {
  int r = 0;
  for (; x > 0; x -= x&-x)
    for (int y = _y; y > 0; y -= y&-y)
      r += bit[x][y];
  
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
      add(x, y, v);
      add(x, w + 1, -v);
      add(z + 1, y, -v);
      add(z + 1, w + 1, v);
    } else {
      scanf ("%d %d", &x, &y);
      printf ("%d\n", sum (x, y));
    }
  }
  
  return 0;
}
