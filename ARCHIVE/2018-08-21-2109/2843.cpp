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

const int S = 1e5+10;
const int N = 66000;

char str[S];
pair<int, int> arr[N];
int comp[N][2];
int ans[N];
int r, e;
ll val;
int aux;

int func (int x, int y) {
  ll a = arr[x].x + arr[x].y*val;
  ll b = arr[y].x + arr[y].y*val;
  if (b < a) {
    ans[x] = aux;
    return y;
  } else {
    ans[y] = aux;
    return x;
  }
}

int main ()
{
  int n;
  scanf ("%d", &n);
  int n1 = n;
  for (int i = 1; i <= n; i++) {
    comp[i][0] = i;
    scanf ("%d %d", &r, &e);
    arr[i].x = r;
    arr[i].y = e;
  }
  getchar();
  scanf ("%[^\n]", str);
  val = strlen (str);
  //printf ("%lld\n", val);
  aux = 1;
  bool now = 1;
  while (n > 1) {
    n /= 2;
    for (int i = 1; i <= n; i++)
      comp[i][now] = func (comp[2*i-1][!now], comp[2*i][!now]);
    now = !now;
    ++aux;
    if (val < 1e10)
      val *= 2;
    //printf ("%lld\n", val);
  }
  ans[comp[1][!now]] = aux;
  for (int i = 1; i <= n1; i++) {
    printf ("%d", ans[i]);
    if (i < n1)
      putchar (' ');
  }
  putchar ('\n');

  return 0;
}
