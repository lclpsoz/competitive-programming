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

const int N = 1e5+10;

int n;
int arr[N], b[N];

int main ()
{
  scanf ("%d", &n);
  for (int i = n-1; i >= 0; i--)
    scanf ("%d", &arr[i]);
  int maxi = -1;
  for (int i = 0; i < n; i++) {
    b[i] = max (0, maxi-arr[i]+1);
    maxi = max (arr[i], maxi);
  }
  for (int i = n-1; i >= 0; i--)
    printf ("%d ", b[i]);

  return 0;
}
