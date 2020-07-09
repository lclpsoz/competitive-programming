#include <bits/stdc++.h>
using namespace std;

int n;
int ans, trash, x;

int main ()
{
	while (scanf ("%d", &n), n) {
		ans = 0;
		for (int i = 0; i < n; i++) {
			scanf ("%d %d", &trash, &x);
			ans += x/2;
		}
		printf ("%d\n", ans/2);
	}
	return 0;
}
