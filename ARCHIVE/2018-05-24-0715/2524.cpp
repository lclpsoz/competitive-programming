#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

const int MAXN = 1e3+10;

int n, m;
int a[MAXN];
int dp[MAXN][1010];
int vis[MAXN][1010];
int t;

int solve (int pos, int val) {
	// printf (" val: %d pos (%d)\n", val, pos);
	if (pos == m) return (val ? -1e9 : 0);
	int &ret = dp[pos][val];
	int &vi = vis[pos][val];
	if (vi != t) {
		vi = t;
		ret = max (	1+solve (pos+1, (val+a[pos])%n),
					solve (pos+1, val)					);
	}

	// printf (" %d\n", ret);
	return ret;
}

int main ()
{
	t = 1;
	while (scanf ("%d %d", &n, &m) != EOF) {
		for (int i = 0; i < m; i++)
			scanf ("%d", &a[i]);
		printf ("%d\n", solve (0, 0));
		t++;
	}

	return 0;
}
