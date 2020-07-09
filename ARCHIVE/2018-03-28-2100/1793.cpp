#include <bits/stdc++.h>
using namespace std;

int i;
int n, ti, ans, bef;

int main ()
{
	while (scanf ("%d", &n), n) {
		bef = 0; ans = 0;
		for (i = 0; i < n; i++) {
			scanf ("%d", &ti);
			if (bef) {
				if (bef - ti > 0)
					ans += 10 - (bef - ti);
				else
					ans += 10;
				bef = ti + 10;
			}
			else {
				bef = ti + 10;
			}
		}
		ans += 10;
		printf ("%d\n", ans);
	}
	return 0;
}
