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

const int SHIFT = 505;
const int N = 1005;

int n, xEnd, yEnd;
queue<pair<pii, int>> q;
pii arr[55];
bool vis[N][N][52];

int main () {
  int x, y;
  scanf ("%d %d %d", &n, &xEnd, &yEnd);
  if (xEnd == 0 && yEnd == 0) {
    printf ("0\n");
    return 0;
  }
  xEnd += SHIFT;
  yEnd += SHIFT;
  for (int i = 1; i <= n; i++) {
    scanf ("%d %d", &x, &y);
    arr[i] = {x, y};
  }

  q.push ({{SHIFT, SHIFT} , 0});
  while (!q.empty()) {
    pii p = q.front().x;
    int d = q.front().y;
    q.pop();
    if (vis[p.x][p.y][d])
      continue;
    //printf ("%d %d\n", p.x, p.y);
    vis[p.x][p.y][d] = true;
    for (int i = d+1; i <= n; i++)
      q.push ({{p.x+arr[i].x,p.y+arr[i].y}, i});
  }

  vector<int> ans;
  bool test = false;
  for (int i = 1; !test && i <= n; i++) {
    while (vis[xEnd][yEnd][i]) {
      test = true;
      xEnd -= arr[i].x;
      yEnd -= arr[i].y;
      ans.push_back (i);
      for (int j = i-1; j > 0; j--)
	if (vis[xEnd][yEnd][j]) {
	  i = j;
	  break;
	}
    }
  }
  if (test) {
    printf ("%d\n", len (ans));
    for (int i = 0; i < len (ans); i++) {
      if (i) putchar (' ');
      printf ("%d", ans[i]);
    }
  } else
    printf ("-1\n");
  
  return 0;
}
