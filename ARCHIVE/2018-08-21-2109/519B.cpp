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
multiset<int> s1, s2;

int main ()
{
  int x;
  int n; scanf ("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf ("%d", &x);
    s1.insert (x); s2.insert (x);
  }
  for (int i = 0; i < n-1; i++) {
    scanf ("%d", &x);
    s1.erase (s1.find (x));
  }
  for (int i = 0; i < n-2; i++) {
    scanf ("%d", &x);
    s2.erase (s2.find (x));
  }
  s2.erase (s2.find(*s1.begin()));
  printf ("%d\n%d\n", *s1.begin(), *s2.begin());
  

  return 0;
}
