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

int n;
int a[110];

int main ()
{
  int x;
  scanf ("%d", &n);
  ll ans = 1;
  int acu = -1;
  bool test = false;
  for (int i = 0; i < n; i++) {
    scanf ("%d", &x);
    if (x)
      test = true;
    if (acu == -1 && x)
      acu = 1;
    else if (acu != -1) {
      if (x == 1 && acu > 0) {
	ans *= acu;
	acu = 1;
      } else if (x == 0)
	++acu;
    }
  }

  if (test)
    printf ("%lld\n", ans);
  else
    printf ("0\n");

  return 0;
}
