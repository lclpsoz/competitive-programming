#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

const int MAXN = 1e3+10;

int n, c, v, w;
int dp[102];

int main ()
{
	int t = 1;
	while (scanf ("%d %d", &n, &c), n || c) {
		memset (dp, -1, sizeof (dp));
		dp[0] = 0;
		int ans = 0;
		for (int j = 0; j < n; j++) {
			scanf ("%d %d", &w, &v);
			for (int i = c; i >= w; i--)
				if (dp[i-w] > -1)
					ans = max (dp[i] = max (dp[i], dp[i-w] + v), ans);
		}

		printf ("Caso %d: %d\n", t++, ans);
	}

	return 0;
}
