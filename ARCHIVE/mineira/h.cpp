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
int bst[MAXN][MAXN];

int dist (char a, char b) {
	if (a < b)
		swap (a, b);
	return min (a-b, b-a+26);
}

int best (int l, int r) {
	// printf ("%d %d\n", l, r);
	if (bst[l][r] != -1) return bst[l][r];
	if (l >= r) return 0;
	return bst[l][r] = (best (l+1, r-1) + dist (str[l], str[r]));
}

int solve (int p, int k) {
	if (p == n) return 0;
	if (dp[p][k] != -1) return dp[p][k];
	int r = INF;

	if (k == 1) {
		r = best (p, n-1);
	} else {
		for (int i = p; i < n; i++)
			r = min (r, best (p, i) + solve (i+1, k-1));
	}

	return dp[p][k] = r;
}

int main ()
{
	/*for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++) {
			printf ("%c %c %d\n", 'a'+i, 'a'+j, dist ('a'+i, 'a'+j));
			if (dist ('a'+i, 'a'+j) != dist ('a'+j, 'a'+i))
				printf (",<<<<<<<<<<,\n");
		}*/
	memset (dp, -1, sizeof (dp));
	memset (bst, -1, sizeof (bst));
	int k;
	scanf ("%d %d", &n, &k);
	scanf ("%s", str);

	printf ("%d\n", solve (0, k));

	return 0;
}
