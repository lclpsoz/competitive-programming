#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2010;

int n, m, q, v;
int dp[2010];

int main ()
{
	while (scanf ("%d %d", &n, &m) != EOF) {
		dp[0] = 0;
		for (int i = 1; i <= m; i++)
			dp[i] = -1;
		while (n--) {
			scanf ("%d %d\n", &q, &v);
			for (int i = q; i <= m; i++)
				if (dp[i-q] > -1)
					dp[i] = max (dp[i], dp[i-q]+v);

			/*for (int i  = 0; i <= m; i++)
				printf ("%d ", dp[i]);
			putchar ('\n');*/
		}

		printf ("%d\n", dp[m]);
	}

	return 0;
}
