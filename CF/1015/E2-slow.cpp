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
char mat2[N][N];
int qnt = 0;

bool func (int x, int y, int sz, bool verif) {
  //printf ("%d %d %d\n", x, y, sz);
  for (int i = x-sz; i <= x+sz; i++) {
    if (!verif && mat[i][y] == '.')
      return false;
    if (verif) mat[i][y] = '.';
  }
  for (int i = y-sz; i <= y+sz; i++) {
    if (!verif && mat[x][i] == '.')
      return false;
    if (verif) mat[x][i] = '.';
  }
  bool aux = false;
  for (int i = x-sz; i <= x+sz; i++)
    if (mat[i][y] == '*')
      aux = true;
  for (int i = y-sz; i <= y+sz; i++)
    if (mat[x][i] == '*')
      aux = true;
  if (!aux) return false;
  
  for (int i = x-sz; i <= x+sz; i++) {
    if (mat[i][y] == '*')
      --qnt;
    mat[i][y] = '-';
  }
  for (int i = y-sz; i <= y+sz; i++) {
    if (mat[x][i] == '*')
      --qnt;
    mat[x][i] = '-';
  }
  
  return true;
}

int main () {
  scanf ("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      scanf (" %c", &mat[i][j]);
      qnt += mat[i][j] == '*';
    }

  std::vector<pp> vec;
  int aux = n*m;
  for (int sz = 1; sz < n && sz < m; sz++) {
    if (!qnt)
      break;
    for (int i = sz; i < n-sz; i++)
      for (int j = sz; j < m-sz; j++)
	if (qnt && func (i, j, sz, false))
	  vec.push_back ({{i, j}, sz});
  }
  for (auto p : vec)
    //printf ("[%d]\n", func (p.x.x, p.x.y, p.y, true));
    func (p.x.x, p.x.y, p.y, true);

  if (qnt)
    printf ("-1\n");
  else {
    printf ("%d\n", len (vec));
    for (auto p : vec)
      printf ("%d %d %d\n", p.x.x+1, p.x.y+1, p.y);
  }
  
  return 0;
}
