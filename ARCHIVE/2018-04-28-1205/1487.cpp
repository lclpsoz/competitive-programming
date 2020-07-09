#include <bits/stdc++.h>
using namespace std;

int n, t;
int d, p;
int ans;
int ins;
int dp[610];

int main ()
{
	while (scanf ("%d %d", &n, &t), n || t) {
		ins++;
		dp[0] = 0;
		for (int i = 1; i <= t; i++)
			dp[i] = -1;
		while (n--) {
			scanf ("%d %d", &d, &p);
			for (int i = d; i <= t; i++)
				if (dp[i-d] > -1)
					dp[i] = max (dp[i], dp[i-d]+p);
		}
		ans = 0;
		for (int i = 0; i <= t; i++)
			ans = max (ans, dp[i]);

		printf ("Instancia %d\n", ins);
		printf ("%d\n\n", ans);
	}

	return 0;
}
