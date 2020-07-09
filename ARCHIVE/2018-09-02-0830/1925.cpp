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

const int MOD = 1e9 + 7;
int mod (ll x, ll m = MOD) {
  return ((x%m) + m)%m;
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e3+10, NN = 1e6+10;

int n, m;
char room[N][N];
int mat[N][N];
int adj[][2] = {{0, 1},
		{1, 0},
		{0, -1},
		{-1, 0}};
int qnt[NN];

void dfs (int x, int y, int id) {
  if (room[x][y] != 'n')
    return;
  ++qnt[id];
  room[x][y] = '-';
  mat[x][y] = id;
  for (int i = 0; i < 4; i++)
    dfs (x+adj[i][0], y+adj[i][1], id);
  //printf ("  (%d %d) -> %d\n", x, y, r);
}

int verif (int x, int y) {
  int r = 0;
  set<int> s;
  for (int i = 0; i < 4; i++)
    s.insert(mat[x+adj[i][0]][y+adj[i][1]]);
  for (int z : s)
    r += qnt[z];

  return r;
}

int main () {
  scanf ("%d %d", &n, &m);
  getchar();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      scanf ("%c", &room[i][j]);
    getchar();
  }

  int id = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (room[i][j] == 'n')
	dfs (i, j, id++);
  
  pii ans;
  int maxi = -1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      //printf ("%d", mat[i][j]);
      if (room[i][j] == '*') {
	int f = verif (i, j);
	if (f > maxi) {
	  maxi = f;
	  ans = {i, j};
	}
      }
    }
    //putchar ('\n');
  }
  //for (int i = 0; i < id; i++)
  //  printf ("%d: %d\n", i, qnt[i]);

  printf ("%d,%d\n", ans.x, ans.y);
  
  return 0;
}
