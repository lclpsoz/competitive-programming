#include <bits/stdc++.h>
using namespace std;

int i;
int n, x, c, ans;

int main ()
{
	while (scanf ("%d", &n) != EOF) {
		ans = -1;
		for (i = 0; i < n-1; i++) {
			scanf ("%d %d", &x, &c);
			if (x == n)
				c ? ans = 0 : ans = 1;
			else if (ans > -1 && c)
				ans++;
		}
		printf ("%d\n", ans);
	}
	return 0;
}
