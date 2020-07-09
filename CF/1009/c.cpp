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

int n, m;
int x, d;

int main ()
{
	ld ans = 0;
	cin >> n >> m;
	while (m--) {
		scanf ("%d %d", &x, &d);
		ans += x*n;
		if (d < 0) {
			ll n2 = n/2;
			++n2;
			if (n%2 == 0) {
				ans -= (n2-1)*d;
				ans += ((1LL*(n2)*(n2-1))/2LL)*d*2LL;
			} else
				ans += ((1LL*(n2)*(n2-1))/2LL)*d*2LL;
		} else if (d > 0) {
			ans += ((1LL*(n)*(n-1))/2LL)*d;
		}
		// printf ("%.20Lf\n", ans);
	}

	printf ("%.20Lf\n", ans/n);

  return 0;
}
