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

const int N = 1e6+10;

int n, m;
bool vis[N];
int main ()
{
  scanf ("%d %d", &n, &m);
  queue<pii> q;
  q.push ({n, 0});
  int m2 = 2*m;
  while (q.front().x != m) {
    pii p = q.front(); q.pop();
    if (vis[p.x]) continue;
    vis[p.x] = true;
    //printf ("%d %d\n", p.x, p.y);
    if (p.x*2 < N)
      q.push ({p.x*2, p.y+1});
    if (p.x-1 > 0)
      q.push ({p.x-1, p.y+1});
  }
  printf ("%d\n", q.front().y);

  return 0;
}
