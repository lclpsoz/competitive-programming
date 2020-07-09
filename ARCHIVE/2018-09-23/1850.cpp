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

const int CH = 1<<7;

char mat[110][110];
queue<pair<pii, pii>> q;
int adj[][2] = {{0, 1},
		{1, 0},
		{0, -1},
		{-1, 0}};
int vis[110][110][CH];

void func (pii p, int ch, int w) {
  //printf ("%d %d\n", p.x, p.y);
  for (int i = 0; i < 4; i++) {
    int x = p.x+adj[i][0];
    int y = p.y+adj[i][1];
    char c = mat[x][y];
    if ('a' <= c && c <= 'g')
      q.push({{w+1, ch | 1 << (c-'a')}, {x, y}});
    else if (c == '@' || c == '.' || c == '*' || (('A' <= c && c <= 'G') && ch & (1<<(c-'A'))))
      q.push({{w+1, ch}, {x, y}});
  }
}

int main () {
  int i = 1;
  pii st, en;
  while (scanf ("%[^\n]", &mat[i][1]) != EOF) {
    getchar();
    for (int j = 1; mat[i][j] != '\0'; j++)
      if (mat[i][j] == '@') {
	st = {i, j};
      } else if (mat[i][j] == '*')
	en = {i, j};
    //printf ("%s\n", mat[i]+1);
    i++;
  }
  //printf ("%d %d %d %d\n", st.x, st.y, en.x, en.y);

  q.push ({{0, 0}, {st.x, st.y}});
  while (!q.empty() && (q.front().y.x != en.x || q.front().y.y != en.y)) {
    //printf ("%ld\n", q.size());
    int w = q.front().x.x;
    int ch = q.front().x.y;
    pii p = q.front().y;
    q.pop();
    if (vis[p.x][p.y][ch]) continue;
    vis[p.x][p.y][ch] = true;
    func (p, ch, w);
  }
  if (q.empty())
    printf ("--\n");
  else
    printf ("%d\n", q.front().x.x);
  
  return 0;
}
