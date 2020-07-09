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
int l, r;
bool ok;
int x, y;
vector<int> v;

int main ()
{
  scanf ("%d", &n);
  y = -100;
  l = r = -1;
  int aux, bef;
  for (int i = 1; i <= n; i++) {
    scanf ("%d", &x);
    v.pb (x);
    //printf ("%d %d\n", x, y);
    if (x < y && r == -1 && !ok) {
      ok = true;
      l = i-1;
    } else if (x > y && ok && r == -1) {
      r = i-1;
    }
    else if (x < y && r != -1) {
      cout << "no\n";
      return 0;
    }
    y = x;
  }
  if (ok && r == -1)
    r = n;
  if (l == -1) {
    l = r = 1;
  }
  reverse (v.begin()+l-1, v.begin()+r);
  for (int i = 1; i < v.size(); i++)
    if (v[i] < v[i-1]) {
      puts ("no");
      return 0;
    }
  printf ("yes\n%d %d\n", l, r);

  return 0;
}
