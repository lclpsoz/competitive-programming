#include <bits/stdc++.h>
using namespace std;

int h, n;
int bef, now, ans;

int main ()
{
	while (scanf ("%d %d", &h, &n), h) {
		ans = 0;
		bef = h;
		for (int i = 0; i < n; i++) {
			scanf ("%d", &now);
			if ((bef - now) > 0)
				ans += bef - now;
			bef = now;
		}
		printf ("%d\n", ans);
	}

	return 0;
}
