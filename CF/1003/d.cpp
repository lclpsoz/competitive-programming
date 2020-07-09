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

int n, q;
int arr[50];
int aux[50];
int x;

bool func (int i, int acu = 1) {
  if (i < 0) return false;
  if (acu == 0) return true;
  if (aux[i]) {
    acu -= aux[i];
    aux[i] = 0;
    if (acu <= 0) {
      aux[i] = -acu;
      return true;
    }
  }
  return func (i-1, acu*2);
}

int main ()
{
  scanf ("%d %d", &n, &q);
  for (int i = 0; i < n; ++i) {
    scanf ("%d", &x);
    arr[__builtin_ctz (x)]++;
  }
  while (q--) {
    for (int i = 0; i < 50; ++i)
      aux[i] = arr[i];
    scanf ("%d", &x);
    int i = 0;
    int ans = 0;
    while (x) {
      if (x&1)
	if (!func (i)) {
	  ans = -1;
	  break;
	}
      x >>= 1;
      ++i;
    }
    if (ans == 0) {
      for (int j = 0; j < 50; ++j)
	ans += arr[j]-aux[j];
    }
    printf ("%d\n", ans);
  }

  return 0;
}
