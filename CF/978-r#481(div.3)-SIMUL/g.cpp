#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 102;

int n, m;
int s, d, c;
vector<int> ativ[MAXN];
int prep[MAXN];
int fim[MAXN];
int ans[MAXN];
bool dp[MAXN][MAXN][MAXN];

bool solve (int d) {
	// printf ("%d\n", d);
	if (d == n+1) return true;
	// printf ("%d %d\n", prep[fim[d]], fim[d]);
	if (prep[fim[d]]) return false;
	if (!fim[d]) {
		for (int a : ativ[d]) {
			if (prep[a]) {
				if (!dp[d][a][prep[a]]) continue;
				prep[a]--;
				ans[d] = a;
				if (solve (d+1))
					return true;
				prep[a]++;
				dp[d][a][prep[a]] = false;
			}
		}
	} else if (fim[d])
		ans[d] = m+1;
	else
		ans[d] = 0;

	return solve (d+1);
}

int main ()
{
	memset (dp, 1, sizeof (dp));
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf ("%d %d %d", &s, &d, &c);
		fim[d] = i;
		for (int j = s; j <= d; j++)
			ativ[j].push_back (i);
		prep[i] = c;
	}

	if (solve (1)) {
		for (int i = 1; i <= n; i++)
			printf ("%d ", ans[i]);
		putchar ('\n');
	} else {
		printf ("-1\n");
	}


	return 0;
}
