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

const int N = 1e6+10;

int d, e;
ll r;
bool check[N];

int main ()
{
  scanf ("%d %d", &d, &e);
  if (d == 1 || e == 1)
    printf ("1\n");
  else {
    if (d > e) swap (d, e);
    if (d == e) {
      printf ("IMPOSSIVEL\n");
    } else {
      r = d;
      ll a, b;
      while (true) {
	//printf ("%lld %lld\n", r, r%e);
	if (r%e == 1) {
	  a = (r/d) + (r/e);
	  break;
	} else if (r%e == e-1) {
	  a = (r/d) + (r/e) + 1;
	  break;
	}
	else {
	  r += d;
	  if (check[r%e]) {
	    a = -1;
	    break;
	  }
	  check[r%e] = true;
	}
      }
      if (a == -1)
	printf ("IMPOSSIVEL\n");
      else
	printf ("%lld\n", a);
    }
  }

  return 0;
}
