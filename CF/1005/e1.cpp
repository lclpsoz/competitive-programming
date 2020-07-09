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

const int MAXN = 2e5+10;

int n, m;
int arr[MAXN];
map<int, int> pre, suf;

int main ()
{
	scanf ("%d %d", &n, &m);
	int pivo;
	for (int i = 0; i < n; i++) {
		scanf ("%d", &arr[i]);
		if (arr[i] == m) pivo = i;
	}
	int aux = 0;
	for (int i = pivo-1; i >= 0; i--) {
		if (arr[i] < m) --aux;
		else	++aux;
		++pre[aux];
		// printf ("  %d\n", aux);
	}
	aux = 0;
	for (int i = pivo+1; i < n; i++) {
		if (arr[i] < m) --aux;
		else	++aux;
		++suf[aux];
		// printf ("  %d\n", aux);
	}
	ll ans = 1; // Itself
	ans += pre[1];
	ans += suf[1];
	ans += pre[0];
	ans += suf[0];
	// printf ("%d\n", pivo);
	// cout << ans << '\n';
	for (auto p : pre) {
		if (suf.count(-p.x)) {
			// printf ("|%d %d %d %d\n", p.x, p.y, suf[-p.x], p.y);
			ans += 1LL*suf[-p.x]*p.y;
			pre[p.x] = 0;
		}
		if (suf.count(-p.x+1)) {
			// printf ("|+1|%d %d %d %d\n", p.x, p.y, suf[-p.x], p.y);
			ans += 1LL*suf[-p.x+1]*p.y;
			pre[p.x] = 0;
		}
	}
	for (auto p : suf)
		if (pre.count(-p.x) && pre[p.x]) {
			// printf ("||%d %d %d %d\n", p.x, p.y, pre[-p.x], p.y);
			ans += 1LL*pre[-p.x]*p.y;
		}

	printf ("%lld\n", ans);


  return 0;
}
