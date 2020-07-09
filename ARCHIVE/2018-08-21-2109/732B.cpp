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

int n, k;
int x, y;
vector<int> v;

int main ()
{
  cin >> n >> k;
  y = k;
  int ans = 0;
  while (n--) {
    scanf ("%d", &x);
    if (x+y < k) {
      //printf ("%d\n", x+y);
      ans += k-(x+y);
      x = k-y;
      //printf ("x: %d\n", x);
    }
    v.pb (x);
    y = x;
  }
  cout << ans << '\n';
  for (int xx : v)
    cout << xx<< ' ';
  putchar ('\n');

  return 0;
}
