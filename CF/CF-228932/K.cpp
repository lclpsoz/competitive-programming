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

const int N = 23;

int m, n, k;
vector<int> vert;
int base[N][N], dist[N][N];

void cpyBase () {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      dist[i][j] = base[i][j];
}

int main () {
  scanf ("%d %d %d", &n, &m, &k);
  while (k--) {
    int x;
    scanf ("%d", &x);
    vert.push_back (x);
  }
  while (m--) {
    int x, y, w;
    scanf ("%d %d %d", &x, &y, &w);
    base[x][y] = base[y][x] = min (base[x][y], min (base[y][x], w));
  }
  cpyBase();
  
  
  return 0;
}
