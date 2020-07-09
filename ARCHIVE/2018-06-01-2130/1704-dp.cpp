#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;

int n, h;
int v, t;
bool dp[1005][2];
vector<int> vals[1005];
int ans, total;

int main ()
{
	while (scanf ("%d %d", &n, &h) != EOF) {
		ans = total = 0;
		for (int i = 0; i <= 1000; i++) dp[i][0] = dp[i][1] = false;
		dp[0][0] = dp[0][1] = true;
		while (n--) {
			scanf ("%d %d", &v, &t);
			vals[t].pb (v);
			total += v;
		}
		for (int j = h; j >= 1; j--) {
			for (int v : vals[j])
				for (int i = 1000; i >= v; i--)
					if (dp[i-v][!(j&1)]) {
						dp[i][j&1] = true;
						ans = max (ans, i);
						// printf (" %d\n", ans);
					}
			vals[j].clear();
		}

		printf ("%d\n", total-ans);
	}

	return 0;
}
