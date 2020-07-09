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

int a, b;

int main ()
{
  int n;
  int x;
  n = 16;
  for (int i = 0; i < n; i++) {
    scanf ("%d", &x);
    if (x == 1)
      a = i;
    else if (x == 9)
      b = i;
  }
  if (abs (a-b) <= 1 && (a/2 == b/2))
    printf ("oitavas\n");
  else if (abs(a-b) <= 3 && (a/4 == b/4))
    printf ("quartas\n");
  else if (abs(a-b) <= 7 && (a/8 == b/8))
    printf ("semifinal\n");
  else
    printf ("final\n");

  return 0;
}
