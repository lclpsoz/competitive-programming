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

using llu = long long unsigned;

llu n, c, p;
vector<pair<llu, llu>> vec;

llu mdc (llu a, llu b) {
  if (b == 0) return a;
  return mdc (b, a%b);
}

llu mmc (llu a, llu b) {
  return (a*b)/mdc (a, b);
}

int main ()
{
  scanf ("%llu", &n);

  llu m = 1;
  while (n--) {
    scanf ("%llu %llu", &c, &p);
    vec.pb ({c, p});
    m = mmc (m, p);
  }

  llu aux = 0;
  for (auto v : vec) {
    aux += (v.x*(m/v.y));
  }
  //printf ("%llu\n", aux);
  if (aux > m)
    printf ("FAIL\n");
  else
    printf ("OK\n");

  return 0;
}
