#include <bits/stdc++.h>
using namespace std;

int n;
int ans;

int main ()
{
	scanf ("%d ", &n);
	char c = getchar (), now;
	ans = n;
	for (int i = 1; i < n; i++) {
		now = getchar ();
		if ((c == 'U' && now == 'R') || (c == 'R' && now == 'U')) {
			ans--;
			c = 'D';
		}
		else c = now;
	}

	printf ("%d\n", ans);

	return 0;
}
