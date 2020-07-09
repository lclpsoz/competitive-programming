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


int n, st;
int arr[110];

int main ()
{
  scanf ("%d %d", &n, &st);
  for (int i = 1; i <= n; i++)
    scanf ("%d", &arr[i]);

  int ans = arr[st];

  int i = st-1, j = st+1;
  while (i >= 1 && j <= n) {
    if (arr[i] && arr[j])
      ans += 2;
    --i; ++j;
  }
  while (i >= 1) {
    if (arr[i])
      ++ans;
    --i;
  }
  while (j <= n) {
    if (arr[j])
      ++ans;
    ++j;
  }
  printf ("%d\n", ans);

  return 0;
}
