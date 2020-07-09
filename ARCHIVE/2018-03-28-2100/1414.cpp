#include <bits/stdc++.h>
using namespace std;

int t, n, ans, x;

int main ()
{
	while (scanf ("%d", &t), t) {
		ans = 0;
		scanf ("%d", &n);
		for (int i = 0; i < t; i++) {
			scanf ("%*s %d", &x);
			ans += x;
		}
		printf ("%d\n", (3*n)-ans);
	}


	return 0;
}
