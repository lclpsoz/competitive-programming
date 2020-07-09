#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 410;
const int INF = 1e9;

int n;
char str[MAXN];
int dp[MAXN][MAXN];

int dist (char a, char b) {
	if (a < b)
		swap (a, b);
	return min (a-b, b-a+26);
}

int best (int l, int r) {
	printf ("%d %d\n", l, r);
	if (l >= r) return 0;
	return best (l+1, r-1) + dist (str[l], str[r]);
}

int solve (int p, int k) {
	int r = INF;

	if (k == 1) {
		r = best (p, n-1);
	} else {
		for (int i = p; i <= n-k; i++)
			r = min (r, best (p, i) + solve (i+1, k-1));
	}

	return r;
}

int main ()
{
	memset (dp, -1, sizeof (dp));
	int k;
	scanf ("%d %d", &n, &k);
	scanf ("%s", str);

	printf ("%d\n", solve (0, k));

	return 0;
}
