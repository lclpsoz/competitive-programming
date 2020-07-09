#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

const int MAXN = 1e5+10;

int dp[MAXN];
int vals[MAXN];

bool solve (int v, int i) {
	if (v == 0)	return true; // Caso base
	if (i == 0) return false;
	if (dp[v] != -1) return dp[v];
	bool ret = false;

	if (solve (v, i-1))
		ret = true;
	else if ((v-vals[i]) >= 0 && solve(v-vals[i], i-1))
		ret = true;

	return dp[v] = ret;
}

int main ()
{
	memset (dp, -1, sizeof(dp));
	int n, v;
	scanf ("%d %d", &v, &n);
	for (int i = 1; i <= n; i++)
		scanf ("%d", &vals[i]);

	dp[0] = true;
	for (int i = 0; i <= 3; i++)
		printf ("%d ", dp[i]);
	putchar ('\n');
	printf ("%s\n", solve (v, n) ? "S" : "N");

	return 0;
}
