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

int s, n;
int x, y;
vector<pii> v;

int main ()
{
  scanf ("%d %d", &s, &n);
  while (n--) {
    scanf ("%d %d", &x, &y);
    v.pb ({x, y});
  }
  sort (v.begin(), v.end());
  for (pii p : v) {
    if (s <= p.x) {
      printf ("NO\n");
      return 0;
    } else {
      s += p.y;
    }
  }
  printf ("YES\n");

  return 0;
}
