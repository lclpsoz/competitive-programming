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

const int N = 1e4+10;

int n;
int a[N];

int main ()
{
  cin >> n;
  for (int i = 0; i < n; i++)
    scanf ("%d", &a[i]);
  sort (a, a+n);
  for (int i = a[n-1]+1;; i++) {
    bool tst = false;
    for (int j = 0; j < n; j++)
      if (a[j] > 1 && i%a[j] == 0) {
	//printf ("%d %d\n", i, a[j]);
	tst = true;
	break;
      }
    if (tst) continue;
    printf ("%d\n", i);
    return 0;
  }

  return 0;
}
