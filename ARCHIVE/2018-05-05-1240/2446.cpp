#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;

int v, m;
bool dp[MAXN];
int x;

int main ()
{
	scanf ("%d %d", &v, &m);
	dp[0] = true;
	while (m--) {
		scanf ("%d", &x);
		for (int i = v; i >= x; i--)
			if (dp[i-x])
				dp[i] = true;
	}

	printf ("%c\n", dp[v] ? 'S' : 'N');

	return 0;
}
