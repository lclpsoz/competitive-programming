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
int x;
bool check[110];
int go[110], back[110], order[110];

bool forward () {
  for (int i = 0; i < n-1; i++)
    if (order[i]) {
      check[order[i]] = true;
      if (order[i+1]) {
	if (check[order[i+1]])
      }
    }
}

int main ()
{
  scanf ("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf ("%d", &x);
    go[i] = x; // i will give to x
    back[x] = i; // x will receive to i
  }
  for (int i = 0; i < n; i++)
    scanf ("%d", &order[i]);
  forward();

  return 0;
}
