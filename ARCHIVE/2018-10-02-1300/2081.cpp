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

using pp = pair<int, pair<pii, pii>>;
const int N = 55;

int t;
int row, col;
pii pos1, pos2;
queue<pp> q;
char mat1[N][N], mat2[N][N];
int adj[][2] = {{0, 1},
		{1, 0},
		{0, -1},
		{-1, 0}};
bool vis[N][N][N][N];

int main () {
  scanf ("%d", &t);
  while (t--) {
    scanf ("%d %d", &row, &col);
    for (int i = 0; i <= row+1; i++)
      mat2[i][0] = mat2[i][col+1] =
	mat1[i][0] = mat1[i][col+1] = 'B';
    for (int i = 0; i <= col; i++)
      mat1[0][i] = mat1[row+1][i] =
	mat2[0][i] = mat2[row+1][i] = 'B';
    
    for (int i = 1; i <= row; i++)
      for (int j = 1; j <= col; j++) {
	scanf (" %c", &mat1[i][j]);
	if (mat1[i][j] == 'R') {
	  pos1 = {i, j};
	  mat1[i][j] = '.';
	}
      }
    for (int i = 1; i <= row; i++)
      for (int j = 1; j <= col; j++) {
	scanf (" %c", &mat2[i][j]);
	if (mat2[i][j] == 'R') {
	  pos2 = {i, j};
	  mat2[i][j] = '.';
	}
      }
    memset (vis, false, sizeof vis);
    q.push ({0, {pos1, pos2}});
    int ans = -1;
    while (ans == -1 && !q.empty() && q.front().x <= 50) {
      int w = q.front().x;
      pos1 = q.front().y.x;
      pos2 = q.front().y.y;
      q.pop();
      if (vis[pos1.x][pos1.y][pos2.x][pos2.y])
	continue;
      vis[pos1.x][pos1.y][pos2.x][pos2.y] = true;
      if (mat1[pos1.x][pos1.y] == 'F' &&
	  mat2[pos2.x][pos2.y] == 'F') {
	ans = w;
	break;
      }
      for (int i = 0; i < 4; i++) {
	char c1, c2;
	c1 = mat1[pos1.x+adj[i][0]][pos1.y+adj[i][1]];
	c2 = mat2[pos2.x+adj[i][0]][pos2.y+adj[i][1]];
	//printf ("|%c %c\n", c1, c2);
	if (c1 == 'B' || c2 == 'B')
	  continue;
	if (c1 == c2 && c1 == '#')
	  continue;
	pii nxt1 = pos1, nxt2 = pos2;
	if (c1 != '#')
	  nxt1 = {pos1.x+adj[i][0],
		  pos1.y+adj[i][1]};
	if (c2 != '#')
	  nxt2 = {pos2.x+adj[i][0],
		  pos2.y+adj[i][1]};
	q.push ({w+1, {nxt1, nxt2}});
      }
    }
    if (ans == -1)
      printf ("impossivel\n");
    else
      printf ("%d\n", ans);
    while (!q.empty())
      q.pop();
  }
  
  return 0;
}
