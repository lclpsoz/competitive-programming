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

const int MOD = 1000000007;

ll x, y, n;

int main ()
{
  scanf ("%lld %lld %lld", &x, &y, &n);
  n = ((n-1)%6)+1;
  for (int i = 1; i < n; i++) {
    int z = y-x;
    swap (x, y);
    y = z;
  }
  x += 3LL*MOD;
  x %= MOD;
  printf ("%lld\n", x);
    
  return 0;
}
