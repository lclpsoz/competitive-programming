#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2010;

int n, t;
int len, val;
int dp[MAXN];

int main ()
{
	scanf ("%d %d", &n, &t);
	for (int i = 1; i < MAXN; i++) dp[i] = -1;
	while (n--) {
		scanf ("%d %d", &len, &val);
		for (int i = len; i <= t; i++)
			if (dp[i-len] > -1)
				dp[i] = max (dp[i], dp[i-len]+val);
		/*for (int i = 0; i <= t; i++)
			printf ("%d ", dp[i]);
		putchar ('\n');*/
	}
	int ans = 0;
	for (int i = 0; i <= t; i++) ans = max (ans, dp[i]);
	printf ("%d\n", ans);

	return 0;
}
