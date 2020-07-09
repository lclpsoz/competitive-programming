#include <bits/stdc++.h>
using namespace std;

int g;
int p, maxi, val, wei;
int dp[1010];
int ans;

int main ()
{
	scanf ("%d", &g);
	for (int i = 1; i <= g; i++) {
		scanf ("%d %d", &p, &maxi);
		dp[0] = 0;
		for (int j = 1; j <= maxi; j++) dp[j] = -1;
		while (p--) {
			scanf ("%d %d", &val, &wei);
			for (int j = maxi; j-wei >= 0; j--)
				if (dp[j-wei] > -1)
					dp[j] = max (dp[j], dp[j-wei]+val);
		}
		ans = 0;
		for (int j = 0; j <= maxi; j++)
			ans = max (dp[j], ans);
		printf ("Galho %d:\n", i);
		printf ("Numero total de enfeites: %d\n\n", ans);
	}

	return 0;
}
