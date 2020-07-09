#include <bits/stdc++.h>
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define pb push_back
#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cerr << #x " is " << (x) << endl
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int INF = 1e9;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

int n;
ll fib[45];

int main ()
{
  fib[0] = 1;
  fib[1] = 1;
  for (int i = 2; i <= 40; i++)
    fib[i] = fib[i-1]+fib[i-2];
  cin >> n;
  for (int i = n-1; i >= 0; i--) {
    printf ("%lld", fib[i]);
    if (i > 0)
      putchar (' ');
  }
  putchar ('\n');

  return 0;
}
