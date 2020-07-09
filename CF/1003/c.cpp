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

const int MAXN = 5050;

int n, k;
int arr[MAXN];

int main ()
{
  scanf ("%d %d", &n, &k);
  int x;
  for (int i = 1; i <= n; ++i) {
    scanf ("%d", &x);
    arr[i] = arr[i-1]+x;
  }

  ld ans = 0;
  int sum = 0;
  for (int i = k; i <= n; ++i) {
    sum = 0;
    ld aux;
    for (int j = i; j <= n; ++j) {
      aux = (arr[j]-arr[j-i])/(i*1.0);
      if (cmp (ans, aux) == -1)
	ans = aux;
    }
  }
  printf ("%.20Lf\n", ans);

  return 0;
}
