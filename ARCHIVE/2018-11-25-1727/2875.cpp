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

const int NM = 104;

char mat[NM][NM];
int adj[][2] = {{0, -1},
		{-1, 0},
		{0, 1},
		{1, 0}};
int ori = -1;

void func (int x, int y) {
  mat[x][y] = 'X';
  for (int i = 0; i < 4; i++) {
    if (mat[x+adj[i][0]][y+adj[i][1]] == '0') {
      if (ori == -1)
	ori = i;
      if (ori-i == 1 || (ori-i) == -3)
	printf ("L ");
      else if (ori-i == -1 || (ori-i) == 3)
	printf ("R ");
      printf ("F ");
      ori = i;
      func (x+adj[i][0], y+adj[i][1]);
      return;
    }
  }
  printf ("E\n");
  return;
}

int main () {
  int row, col;
  pii st;
  while (scanf ("%d %d", &row, &col) != EOF) {
    for (int i = 1; i <= row; i++)
      for (int j = 1; j <= col; j++) {
	scanf (" %c", &mat[i][j]);
	if (mat[i][j] == 'X')
	  st = {i, j};
      }
    func (st.x, st.y); 
  }
  
  return 0;
}
