#include <bits/stdc++.h>
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define pb push_back
#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cerr << #x " is " << (x) << endl
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int INF = 1e9;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

char a[3], b[3];

int main ()
{
  scanf ("%s %s", a, b);
  int a1 = abs(a[0]-b[0]);
  int b1 = abs(a[1]-b[1]);
  if (a1 > 2 || b1 > 2 || a1 == 0 || b1 == 0)
    printf ("INVALIDO\n");
  else if ((a1 == 1 && b1 == 2) || (a1 == 2 && b1 == 1))
    printf ("VALIDO\n");
  else
    printf ("INVALIDO\n");

  return 0;
}
