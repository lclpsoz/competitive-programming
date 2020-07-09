#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

int n;
int arr[110];
int dp[110][3]; // 0 → not started, 1 → started, 2 → ended

int v (int x) { return x == 0 ? 1 : -1; }

int func (int i, int opt)
{
	if (i == -1) return 0;
	// if (dp[i][opt] < -1) return dp[i][opt];
	int ret;
	if (opt == 0) {
		ret = max (arr[i]+func (i-1, 0), !arr[i]+func(i-1, 1));
		ret = max (
	}
	else if (opt == 1)
		ret = max (!arr[i]+func (i-1, 1), arr[i]+func(i-1, 2));
	else
		ret = arr[i]+func (i-1, 2);
	return dp[i][opt] = ret;
}

int main ()
{
	memset (dp, -1, sizeof (dp));
	scanf ("%d", &n);

	int ones = 0;
	for (int i = 0; i < n; i++) {
		scanf ("%d", &arr[i]);
		ones += arr[i];
	}

	if (ones == n)
		printf ("%d\n", n-1);
	else {
		int m = max (func (n-1, 0), func (n-1, 1));
		printf ("%d\n", m);
	}

	return 0;
}
