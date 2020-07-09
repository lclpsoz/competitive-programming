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
vector<int> v;

ll mdc(ll a, ll b) {
    if(b == 0) return a;
    return mdc(b, a%b);
}
ll mmc (ll a, ll b) { return (a*b) / mdc(a, b); }

ll mmc (int a, int b, int c) {
  return mmc (a, mmc (b, c));
}

ll func () {
  ll ans = -1;
  for (int i : v)
    for (int j : v)
      for (int k : v)
	ans = max (ans, mmc (i, j, k));
  return ans;
}

int main ()
{
  cin >> n;
  for (int i = 0; i < 5; ++i)
    if (n-i > 0)
      v.pb (n-i);
  printf ("%lld\n", func());

  return 0;
}
