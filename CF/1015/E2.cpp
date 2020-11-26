#include <cstdio>
#include <vector>
#include <algorithm>

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = std::pair<int, int>;
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

using pp = std::pair<pii, int>;
const int N = 1010;

int n, m;
char mat[N][N];
int vals[5][N][N];
int qnt = 0;

bool func (int x, int y, int sz, bool verif) {
  
}

int main () {
  scanf ("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      scanf (" %c", &mat[i][j]);
      qnt += mat[i][j] == '*';
    }

  
  
  return 0;
}
