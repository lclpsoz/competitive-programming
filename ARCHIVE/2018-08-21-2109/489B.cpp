#include <bits/stdc++.h>
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define pb push_back
#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cerr << #x " is " << (x) << endl
#define len(x) (int)x.size()
#define X real()
#define Y imag()
#define mp make_pair
using pii = pair<int, int>;
using ll = long long;
using ld = long double;
const int INF = 1e9;
  
const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

int b[102], g[102];

int main ()
{
  int n, m;
  scanf ("%d", &n);
  for (int i = 0; i < n; i++)
    scanf ("%d", &b[i]);
  sort (b, b+n);

  scanf ("%d", &m);
  for (int i = 0; i < m; i++)
    scanf ("%d", &g[i]);
  sort (g, g+m);

  int l, r;
  l = r = 0;
  int ans = 0;
  while (l < n && r < m) {
    //printf ("%d %d\n", l, r);
    while (r < m && g[r] < b[l]-1)
      ++r;
    if (r == m) break;
    while (l < n && b[l] < g[r]-1)
      ++l;
    if (l == n) break;
    if (abs(b[l]-g[r]) <= 1) {
      ++ans;
      ++l; ++r;
    }
  }
  printf ("%d\n", ans);
  
  return 0;
}
