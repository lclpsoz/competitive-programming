#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int i, j, arr[11], x, ans;

int main ()
{
	scanf ("%d", &t);
	for (i = 0; i < t; i++) {
		scanf ("%d %d", &n, &m);
		for (j = 0; j < m; j++) {
			scanf ("%d", &x);
			arr[x]++;
		}
		ans = 0;
		for (j = 1; j <= n; j++) {
			if (arr[j] > m/2)
				ans = j;
			arr[j] = 0;
		}
		ans ? printf ("%d\n", ans) : printf ("-1\n");
	}
	return 0;
}
