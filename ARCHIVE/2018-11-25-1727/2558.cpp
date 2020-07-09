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

using pp = pair<pii, pii>;
const int RC = 102, MSK = (1<<8)+5;

int n, m;
int row, col;
char mat[RC][RC];
bool vis[RC][RC][MSK];
queue<pp> q;
int adj[][2] = {{0, 1},
		{1, 0},
		{0, -1},
		{-1, 0}};

int main () {
  while (scanf ("%d %d", &n, &m) != EOF) {
    pii st, en;
    int id = '1';
    scanf ("%d %d", &col, &row);
    memset (mat, '\0', sizeof mat);
    for (int i = 1; i <= row; i++)
      for (int j = 1; j <= col; j++) {
	scanf (" %c", &mat[i][j]);
	if (mat[i][j] == 'R')
	  st = {i, j};
	if (mat[i][j] == 'S')
	  en = {i, j};
	if (mat[i][j] == '*')
	  mat[i][j] = (char)id++;
      }

    memset (vis, false, sizeof vis);
    q.push ({{0, 0}, st});
    vis[st.x][st.y][0] = true;
    while (!q.empty()) {
      int d = q.front().x.x;
      int msk = q.front().x.y;
      int x = q.front().y.x;
      int y = q.front().y.y;
      q.pop();
      //printf ("  %d %d %d\n", x, y, msk);
      if (d == m)
	continue;
      for (int i = 0; i < 4; i++) {
	int a = x+adj[i][0], b = y+adj[i][1];
	//printf ("    %d %d: %c\n", a, b, mat[a][b]);
	char c = mat[a][b];
	if (c >= '1' && c <= '9') {
	  int aux = msk | (1 << (c-'1'));
	  if (vis[a][b][aux])
	    continue;
	  vis[a][b][aux] = true;
	  q.push ({{d+1, aux}, {x+adj[i][0], y+adj[i][1]}});
	}
	else if (c != '#' && c != '\0') {
	  if (vis[a][b][msk])
	    continue;
	  vis[a][b][msk] = true;
	  q.push ({{d+1, msk}, {x+adj[i][0], y+adj[i][1]}});
	}
      }
    }
    int ans = -1;
    for (int i = MSK-1; i >= 0; i--)
      if (vis[en.x][en.y][i])
	ans = max (ans, __builtin_popcount (i));
    printf ("%d\n", ans);
  }
  
  return 0;
}
