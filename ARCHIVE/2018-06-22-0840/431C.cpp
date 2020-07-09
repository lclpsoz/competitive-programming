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

const int MOD = 1e9+7;

int n, k, d;
pair<ll, ll> dp[2][105];

int main ()
{
	cin >> n >> k >> d;

	bool p = 0;
	int ni = min (n, k);
	for (int i = 1; i <= ni; i++)
		if (i >= d)
			dp[p][i].y = 1;
		else
			dp[p][i].x = 1;
	ll ans = dp[p][n].y;
	for (int i = 0; i < n; i++) {
		p = !p;
		for (int v = 1; v <= ni; v++) {
			if (v >= d)
				for (int j = 1; j+v <= n; j++)
					dp[p][j+v].y += dp[!p][j].x+dp[!p][j].y;
			else
				for (int j = 1; j+v <= n; j++) {
					dp[p][j+v].x += dp[!p][j].x;
					dp[p][j+v].y += dp[!p][j].y;
				}
		}
		for (int j = 0; j <= n; j++) {
			dp[!p][j] = {0, 0};
			dp[p][j].x %= MOD;
			dp[p][j].y %= MOD;
			// printf ("{%2lld, %2lld};", dp[p][j].x, dp[p][j].y);
		}
		// putchar ('\n');
		ans += dp[p][n].y;
	}

	cout << ans%MOD << '\n';

	return 0;
}
