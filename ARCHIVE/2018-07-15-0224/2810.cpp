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

int n, m;
vector<pii> coords;


double operator- (const pii &a, const pii &b) {
  pii p = {a.x-b.x, a.y-b.y};
  return sqrt ((p.x+p.x)*(p.y+p.y));
}

int main ()
{
  int x, y;
  scanf ("%d %d", &n, &m);
  for (int i = 1; i <= n+m; i++) {
    scanf ("%d %d", &x, &y);
    for (pii p : coords) {
    }
  }
    
  return 0;
}
