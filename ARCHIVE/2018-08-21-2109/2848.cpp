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

int n, q;
unsigned int a[1010], b[1010];
multiset<unsigned int> s;

int main ()
{
  int l, r, k, g, d;
  scanf ("%d %d", &n, &q);
  for (int i = 0; i < n; i++)
    scanf ("%u", &a[i]);
  
  int qnt;
  while (q--) {
    scanf ("%d %d %d %d %d", &l, &r, &k, &g, &d);
    s.clear();
    for (int i = l-1; i < r; i++)
      s.insert (a[i]);

    auto it = s.begin();
    for (int i = 0; i < k-1; i++)
      ++it;

    qnt = 0;
    for (int i = l-1; i < r; i++)
      qnt += a[i] == *it;
    g = abs(g-qnt);
    d = abs(d-qnt);
    printf ("%d %d ", *it, qnt);
    if (g == d)
      printf ("E\n");
    else if (g > d)
      printf ("D\n");
    else
      printf ("G\n");
  }

  return 0;
}
