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

int n;
int dp[22][22][1010];
int mat[22][22][1010];
int adj[][2] = {{0, 1},
		{0, -1},
		{1, 0},
		{-1, 0},
		{0, 0}};
int tMax;

int func (int x, int y, int t) {
  if (x < 0 || y < 0 || x > 20 || y > 20)
    return 0;
  int &val = dp[x][y][t];
  if (val != -1)
    return val;
  val = 0;
  if (t < tMax)
    for (int i = 0; i < 5; i++)
      val = max (val, func (x+adj[i][0], y+adj[i][1], t+1));
  val += mat[x][y][t];
  
  return val;
}

int main () {
  memset (dp, -1, sizeof (dp));
  int x, y, t;
  scanf ("%d", &n);
  while (n--) {
    scanf ("%d %d %d", &x, &y, &t);
    ++mat[x][y][t];
    tMax = max (tMax, t);
  }

  printf ("%d\n", func (6, 6, 0));
  
  return 0;
}
