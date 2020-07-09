#include <bits/stdc++.h>
using namespace std;

int n, m;
long long a, b, now, bef, ans;

int main ()
{
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &m);
		ans = 0;
		while (m-- && scanf ("%lld", &now) != EOF) {
			if (now+b > a) {
				swap (a, b);
				a += now;
			} else {
				ans += a;
				a = b = 0;
			}
		}
		ans += a;
		a = b = 0;

		printf ("Case %d: %lld\n", i, ans);
	}

	return 0;
}
