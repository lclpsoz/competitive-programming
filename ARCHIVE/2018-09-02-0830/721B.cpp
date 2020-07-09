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

int n, k, sz;
int a[110];
char pass[110];

int main ()
{
  scanf ("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf ("%s", pass);
    ++a[strlen (pass)];
  }
  scanf ("%s", pass);
  sz = strlen (pass);
  int best, worst;
  best = worst = 0;
  for (int i = 1; i < sz; i++)
    best += a[i];
  worst = best + a[sz];
  ++best;

  best += ((best-1)/k)*5;
  worst += ((worst-1)/k)*5;

  printf ("%d %d\n", best, worst);

  return 0;
}
