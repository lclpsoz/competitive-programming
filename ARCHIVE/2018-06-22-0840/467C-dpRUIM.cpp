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
const int INF = 1e9;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

const int MAXN = 5005;

int arr[MAXN];
ll seg[MAXN];
ll dp[MAXN][MAXN];
int n, m;

ll func (int p, int k) {
	cout << p << ' ' << k << '\n';
	if (p+(k*m) > n) return -INF;
	ll &v = dp[p][k];
	if (v != -1) return v;
	if (k == 0) return v = 0;
	for (int i = p; i < n; i++) {
		ll ax = func (i+m, k-1);
		if (ax == -1) break;
		v = max (v, ax+seg[i]);
	}
	if (v == -1) v = -INF;
	// cout << v << '\n';
	return v;
}

int main ()
{
	memset (dp, -1, sizeof(dp));
	int k;
	scanf ("%d %d %d", &n, &m, &k);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		scanf ("%d", &arr[i]);
		if (i >= m) sum -= arr[i-m];
		sum += arr[i];
		if (i >= m-1)
			seg[i-m+1]  = sum;
	}
	sum = 0;
	cout << func (0, k) << '\n';

	return 0;
}
