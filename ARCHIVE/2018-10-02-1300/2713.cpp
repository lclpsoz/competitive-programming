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

const int N = 1e3+10, K = 104;

int n, v;
int vis[N][K];
ld dp[N][K];
int now = 1;
pair<ld, pair<ld, ld>> rooms[N];

int main () {
  int k, d, adv;
  while (scanf ("%d %d %d", &n, &k, &v) != EOF) {
    ld ans = 0;
    for (int i = 0; i < n; i++) {
      scanf ("%d %d", &adv, &d);
      rooms[i].y = {(ld)adv/v, (ld)adv/(v+d)};
      rooms[i].x = rooms[i].y.y-rooms[i].y.x;
    }
    sort (rooms, rooms+n);
    for (int i = 0; i < n; i++)
      if (i < k)
	ans += rooms[i].y.y;
      else
	ans += rooms[i].y.x;
    printf ("%.4Lf\n", ans);
  }
  
  return 0;
}
