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

int n;
int arr[5];

int main ()
{
  scanf ("%d", &n);
  int x;
  while (n--) {
    scanf ("%d", &x);
    arr[x]++;
  }
  int ans = arr[4];
  int z = min (arr[3], arr[1]);
  ans += z;
  arr[3] -= z;
  arr[1] -= z;
  
  ans += arr[2]/2;
  arr[2] %= 2;

  ans += arr[3];

  if (arr[2]) {
    ans += arr[2];
    arr[1] -= arr[2]*2;
  }
  if (arr[1] > 0)
    ans += ceil(arr[1]/4.0);
  
  printf ("%d\n", ans);

  return 0;
}
