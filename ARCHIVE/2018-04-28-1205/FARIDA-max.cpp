#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+10;

int n, m;
long long x, bef_1, bef_2, ans;

int main ()
{
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &m);
		if (m > 1) {
			scanf ("%lld", &bef_2);
			scanf ("%lld", &x);
			bef_1 = max (bef_2, x);
			ans = bef_1;
			for (int i = 2; i < m; i++) {
				scanf ("%lld", &x);
				ans = max (bef_1, bef_2+x);
				bef_2 = bef_1;
				bef_1 = ans;
			}
		}
		else if (m == 1)
			scanf ("%lld", &ans);

		printf ("Case %d: ", i);
		if (m == 0)
			printf ("0\n");
		else
			printf ("%lld\n", ans);
	}

	return 0;
}
