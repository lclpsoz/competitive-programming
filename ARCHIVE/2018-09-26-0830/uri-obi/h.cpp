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

const int N = 1e5+10;

int n, q;
int bit[N];

void add (int i, int v) {
  while (i <= n) {
    bit[i] += v;
    i += i&-i;
  }
}

ll sum (int i) {
  ll r = 0;
  while (i >= 1) {
    r += bit[i];
    i -= i&-i;
  }

  return r;
}

int main()
{
  int opt, l, r, l2, r2;
  scanf ("%d %d", &n, &q);
  while (q--) {
    scanf ("%d", &opt);
    if (opt == 1) {
      int x, y;
      scanf ("%d %d", &x, &y);
      add (x, y);
    } else {
      scanf ("%d %d %d %d", &l, &r, &l2, &r2);
      if (l2 < l) {
	swap (l2, l);
	swap (r2, r);
      }
      ll ans = sum(r)-sum(l-1);
      ans += sum(r2)-sum(l2-1);
      int l_in = max(l, l2);
      int r_in = min (r, r2);
      //printf ("|||%d %d\n", l_in, r_in);
      if (r_in >= l_in)
	ans -= sum(r_in)-sum(l_in-1);
      printf ("%lld\n", ans);
    }
  }

  return 0;
}
