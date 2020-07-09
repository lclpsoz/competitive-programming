#include <bits/stdc++.h>
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define pb push_back
#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cerr << #x " is " << (x) << endl
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int INF = 1e9;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

int n;
int tortas[21][21][1002];
int dp[21][21][1002];
int adj[][2] = {{0, 1},
		{1, 0},
		{-1, 0},
		{0, -1},
		{0, 0}};
int max_t;

int func (int x, int y, int t) {
  if (x < 0 || y < 0 || x > 20 || y > 20 || t > max_t) return 0;
  int &r = dp[x][y][t];
  if (r != -1) return r;
  r = 0;
  for (int i = 0; i < 5; i++)
    r = max (r,
	     tortas[x][y][t] + func (x+adj[i][0], y+adj[i][1], t+1));

  return r;
}

int main ()
{
  int x, y, t;
  scanf ("%d", &n);
  while (n--) {
    scanf ("%d %d %d", &x, &y, &t);
    max_t = max (max_t, t);
    tortas[x][y][t]++;
  }

  memset (dp, -1, sizeof (dp));
  printf ("%d\n", func (6, 6, 0));

  return 0;
}
