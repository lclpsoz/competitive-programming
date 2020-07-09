#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+10;

int arr[MAXN];
int dp[1010][1010];
int n, x;

int func (int l, int r)
{
	// printf ("%d %d\n", l, r);
	if (l > r) return 0;
	if (dp[l][r] > -10000000) return dp[l][r];
	return dp[l][r] = 	max (arr[l] + min(func (l+2, r),   func (l+1, r-1)),
						arr[r] + min(func (l+1, r-1), func (l, r-2)));
}

int main ()
{
	while (scanf ("%d", &n) != EOF) {
		memset (dp, -10000000, sizeof(dp));
		for (int i = 0; i < n; i++)
			scanf ("%d", &arr[i]);

		printf ("%d\n", func (0, n-1));
	}

	return 0;
}
