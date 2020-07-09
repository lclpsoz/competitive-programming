#include <bits/stdc++.h>
using namespace std;

int n, x, ans, j;

int main ()
{
	j = 0;
	while (scanf ("%d", &n), n) {
		for (int i = 1; i <= n; i++) {
			scanf ("%d", &x);
			if (x == i)
				ans = x;
		}
		printf ("Teste %d\n", ++j);
		printf ("%d\n\n", ans);
	}
	return 0;
}
