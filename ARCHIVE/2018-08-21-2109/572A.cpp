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

int na, nb;
int k, m;
int x;

int main ()
{
  scanf ("%d %d %d %d", &na, &nb, &k, &m);
  int mini;
  for (int i = 1; i <= na; i++) {
    scanf ("%d", &x);
    if (i == k)
      mini = x;
  }
  int maxi;
  for (int i = 1; i <= nb; i++) {
    scanf ("%d", &x);
    if (i == nb-m+1)
      maxi = x;
  }
  if (maxi > mini)
    printf ("YES\n");
  else
    puts ("NO");

  return 0;
}
