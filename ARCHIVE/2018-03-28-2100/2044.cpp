#include <bits/stdc++.h>
using namespace std;

int ans, n, x, sum;

int main ()
{
	while (scanf ("%d", &n), n != -1) {
		ans = sum = 0;
		for (int i = 0; i < n; i++) {
			scanf ("%d", &x);
			sum += x;
			if (sum % 100 == 0) {
				ans++;
				sum = 0;
			}
		}
		printf ("%d\n", ans);
	}
	return 0;
}
