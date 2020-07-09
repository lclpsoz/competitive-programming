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
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int INF = 1e9;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

int n, d, k;
vector<pii> ans;
int lst;

void no() {
  printf ("NO\n");
  exit (0);
}

void func (int v, int d, int lvl) {
  if (!lvl || !d) return;
  if (lst == n+1) return;
  for (int i = 0; lst <= n && i < d; ++i) {
    ans.pb ({v, lst});
    lst++;
    func (lst-1, k-1, lvl-1);
  }    
}

int main ()
{
  scanf ("%d %d %d", &n, &d, &k);
  if (n == 1 || (d > 1 && k == 1) || d >= n || (d == 1 && n > 2) || (d == 2 && k < n-1))
    no();
  else if (d == 1) {
    printf ("YES\n");
    printf ("1 2\n");
  } else if (d == 2) {
    printf ("YES\n");
    for (int i = 2; i <= n; ++i)
      printf ("1 %d\n", i);
  } else {// d > 2
    int st = 1;
    int en = 1+d;
    lst = en+1;
    for (int i = 1; i < en; ++i)
      ans.pb ({i, i+1});
    for (int i = 1; i <= en; ++i)
      func (i, k-2, min (i-st, en-i));
    if (ans.size() == n-1) {
      printf ("YES\n");
      for (pii p : ans)
	printf ("%d %d\n", p.x, p.y);
    } else
      no();
  }

  return 0;
}
