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

int t, d;
int v[11];
int num[100];
ll n;

int main ()
{
  scanf ("%d", &t);
  while (t--) {
    scanf ("%d", &d);
    for (int i = 0; i < d; i++)
      scanf ("%d", &v[i]);
    sort (v, v+d);
    int en = 0;
    scanf ("%lld", &n);
    do {
      --n;
      //printf ("n: %lld\n", n);
      num[en] = n%d;
      ++en;
      n /= d;
    } while (n);
    //printf ("en: %d\n", en);
    for (int i = en-1; i >= 0; i--)
      printf ("%d", v[num[i]]);
    putchar ('\n');
  }

  return 0;
}
