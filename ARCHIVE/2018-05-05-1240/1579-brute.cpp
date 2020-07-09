#include <bits/stdc++.h>
using namespace std;

int t, n, tr, f;
int w;
int dp[12][105];
int wei[105];
int vals[105];

int func (int l, int r, int truc)
{
	int ret;
	if (truc == 0 || r == n-1) {
		if (r != n-1)
			return 1e9;
		ret = 0;
		vals[truc] = 0;
		for (int i = l; i <= r; i++)
			vals[truc] += wei[i];
		for (int i = truc; i < tr; i++)
			ret = max(vals[i], ret);
		printf ("%d %d>%d\n", l, r, ret);
		return ret;
	}
	// printf ("%d %d\n", l, r);
	ret = 1e9;

	vals[truc] = 0;
	for (int i = l; i <= r; i++)
		vals[truc] += wei[i];

	if (truc > 1)
		for (int i = r+1; i < n; i++)
			ret = min (ret, func (r+1, i, truc-1));
	else if (truc == 1 && r+1 < n)
		ret = min (ret, func (r+1, n-1, truc-1));

	// printf ("%d %d>%d\n", l, r, ret);
	return ret;
}

int main ()
{
	int sum, maxi;
	scanf ("%d", &t);
	while (t--) {
		memset (dp, -1, sizeof (dp));
		sum = 0;
		maxi = 0;
		scanf ("%d %d %d", &n, &tr, &f);
		for (int i = 0; i < n; i++) {
			scanf ("%d", &wei[i]);
			sum += wei[i];
		}
		int ans = 1e9;
		for (int i = 0; i < n; i++)
			ans = min (ans, func (0, i, tr-1));
		printf ("%d\n", ans);
	}

	return 0;
}
