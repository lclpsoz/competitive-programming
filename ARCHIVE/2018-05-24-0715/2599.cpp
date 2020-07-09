#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 1e4+10;
const int MOD = 1e9+7;

ll dp[MAXN];
int t, tt;
int m;
int a[MAXN];

int solve (int n) {
	if (n <= 0) return 1;
	ll &ret = dp[n];
	if (dp[n] == -1) {
		dp[n] = 0;
		for (int i = 0; i < m; i++)
			ret = (ret+solve (n-a[i]))%MOD;
	}

	return ret;
}

int main ()
{
	int n;
	scanf ("%d", &t);
	for (tt = 1; tt <= t; tt++) {
		memset (dp, -1, sizeof (dp));
		scanf ("%d %d", &n, &m);
		for (int i = 0; i < m; i++)
			scanf ("%d", &a[i]);

		printf ("%d\n", solve (n));
	}

	return 0;
}
