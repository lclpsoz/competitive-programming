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
int a[1010], b[1010];

int main ()
{
	scanf ("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
			scanf ("%d", &a[i]);
	for (int i = 0; i < m; i++)
			scanf ("%d", &b[i]);
	int ans = 0;
	int j = 0;
	for (int i = 0; i < n; i++)
		if (a[i] <= b[j]) {
			++j;
			++ans;
		}
	cout << ans << '\n';

  return 0;
}
