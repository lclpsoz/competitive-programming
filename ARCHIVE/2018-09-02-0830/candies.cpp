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
int arr[N];
int seq[N];

int main ()
{
  scanf ("%d", &n);
  scanf ("%d", &arr[1]);
  seq[1] = 1;
  for (int i = 2; i <= n; i++) {
    scanf ("%d", &arr[i]);
    if (arr[i] > arr[i-1])
      seq[i] = seq[i-1]+1;
    else
      seq[i] = 1;
  }
  int aux = 1;
  for (int i = n-1; i >= 1; i--)
    if (arr[i] > arr[i+1]) {
      ++aux;
      seq[i] = max (seq[i], aux);
    } else
      aux = 1;

  ll ans = 0;
  for (int i = 1; i <= n; i++)
    ans += seq[i];
  
  printf ("%lld\n", ans);

  return 0;
}
