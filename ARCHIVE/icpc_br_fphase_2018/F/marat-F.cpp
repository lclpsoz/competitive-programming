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

const int INF = 1e9;
const int N = 1005, MASK = 2 << 10;

int n, m;
vector<pp> vec;
int dp[MASK][N];

int func (int mask, int p) {
  //printf ("%d %d %d\n", mask, p, __builtin_popcount (mask));
  if (p == vec.size())
    return __builtin_popcount (mask) == n ? 0 :-INF;
  int &r = dp[mask][p];
  if (r != -1)
    return r;
  int now = p;
  while (p < vec.size() && vec[now].x.y > vec[p].x.x)
    ++p;
  r = max (func (mask | (1 << vec[now].y.x), p)+vec[now].y.y,
	   func (mask, now+1));
  //printf ("%d %d: %d\n", mask, p, r);
  
  return r;
}

int main () {
  memset (dp, -1, sizeof (dp));
  scanf ("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf ("%d", &m); 
    int l, r, o;
    for (int j = 0; j < m; j++) {
      scanf ("%d %d %d", &l, &r, &o);
      vec.push_back ({{l, r}, {i, o}});
    }
  }

  sort (vec.begin(), vec.end());
  int v = func (0, 0);
  printf ("%d\n", v < 0 ? -1 : v);
  
  return 0;
}
