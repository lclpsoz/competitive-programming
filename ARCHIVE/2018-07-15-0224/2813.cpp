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

int n;
char a1[10], a2[10];
pii x, y;

int main ()
{
  cin >> n;
  while (n--) {
    scanf ("%s %s", a1, a2);
    if (a1[0] == 'c') {
      if (x.x)
	--x.x;
      else
	++x.y;
      ++y.x;
    }
    if (a2[0] == 'c') {
      if (y.x)
	--y.x;
      else
	++y.y;
      ++x.x;
    }
  }
  printf ("%d %d\n", x.y, y.y);

  return 0;
}
