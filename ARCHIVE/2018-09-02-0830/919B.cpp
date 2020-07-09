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

int n;

bool check (int x) {
  int r = 0;
  //printf ("%d\n", x);
  while (x) {
    r += x%10;
    x/=10;
  }
  //printf ("r: %d\n", r);
  return r == 10;    
}

int main ()
{
  scanf ("%d", &n);
  int aux = 0, i;
  for (i = 19;; i++) {
    if (check (i)) ++aux;
    if (aux == n) break;
  }

  printf ("%d\n", i);

  return 0;
}
