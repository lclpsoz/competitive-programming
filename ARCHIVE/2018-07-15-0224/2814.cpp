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

int t;
int k, n;
pii a = {-1, -1};
pii b = {-1, -1};

int main ()
{
  scanf ("%d", &t);
  while (t--) {
    scanf ("%d %d ", &k, &n);
    a = {-1, -1}; b = {-1, -1};
    for (int i = 0; i < n; i++) {
      char cc = getchar();
      for (int j = 0; cc != '\n' && cc != EOF; j++) {
	//printf ("%d %d\n", i, j);
	if (cc != 'X') {
	  if (a.x == -1)
	    a = {i, j};
	  else
	    b = {i, j};
	}
	cc = getchar();
      }
    }
    //cout << a.x << ' ' << a.y << ' ' << b.x << ' ' << b.y << '\n';
    int d = (int)(sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))*10);
    //cout << d << '\n';
    double val = 0.99;
    if (d == 0)
      val = 1;
    else {
      --d;
      while (d--) {
	val *= 0.99;
      }
    }
    printf ("%d dBs\n", (int)((double)k/val));

  }
  return 0;
}
