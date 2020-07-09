#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

int n;
int a[1005];
int dp[1005][1005];

int solve (int l, int r) {
	if (l > r) return 0; // Caso base
	int &ret = dp[l][r];
	if (ret == -1)
		ret = max (	(a[l]%2==0) + min (solve (l+2, r), solve (l+1, r-1)),
					(a[r]%2==0) + min (solve (l+1, r-1), solve (l, r-2))	);

	/*printf ("  %d %d\n", l, r);
	printf ("  %d %d\n", a[l]%2==0, a[r]%2==0);
	printf ("  %d\n", ret);*/
	return ret;
}

int main ()
{
	while (scanf ("%d", &n), n) {
		memset (dp, -1, sizeof (dp));
		for (int i = 0; i < n<<1; i++)
			scanf ("%d", &a[i]);

		printf ("%d\n", solve (0, (n<<1)-1));
	}

	return 0;
}
