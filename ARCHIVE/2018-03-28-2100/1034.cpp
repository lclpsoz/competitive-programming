#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+10;

int dp[MAXN], arr[28];
int t, n, m;
int i, j, k;

int main ()
{
	scanf ("%d", &t);
	for (i = 0; i < t; i++) {
		scanf ("%d %d", &n, &m);
		for (j = 0; j < n; j++)
			scanf ("%d", &arr[j]);
		dp[0] = 0;
		for (j = 1; j <= m; j++) {
			dp[j] = 1e7;
			for (k = 0; k < n && j-arr[k] >= 0; k++)
				dp[j] = min (dp[j], dp[j-arr[k]]+1);
		}
		printf ("%d\n", dp[m]);
	}
	return 0;
}
