#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

const int MAXN = 44;

int n;
pii a[MAXN];
int dp[805][805][MAXN];
int vis[805][805][MAXN];
int t;
int a1, b, c, d;

int solve (int g, int y, int pos = 0) {
	if (pos == n) return 0; // Caso base
	// printf (" %d %d %d\n", g, y, pos);
	int &ret = dp[g][y][pos];
	int &vi = vis[g][y][pos];
	if (vi != t) {
		vi = t;
		ret = solve (g, y, pos+1);
		a1 = g-abs(a[pos].x);
		b = g+a[pos].x;
		c = y+a[pos].y;
		d = y-abs(a[pos].y);
		if (a1 >= 0 && c >= 0)
			ret = max (ret, 1+solve (a1, c, pos+1));
		if (d >= 0 && b >= 0)
			ret = max (ret, 1+solve (b, d, pos+1));
	}

	// printf (" %d\n", ret);
	return ret;
}

int main ()
{
	int g, y;
	t = 1;
	while (scanf ("%d", &n) != EOF) {
		scanf ("%d %d", &g, &y);
		for (int i = 0; i < n; i++)
			scanf ("%d %d", &a[i].x, &a[i].y);

		printf ("%d\n", solve(g, y));
		t++;
	}

	return 0;
}
