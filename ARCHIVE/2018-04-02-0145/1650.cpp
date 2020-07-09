#include <bits/stdc++.h>
using namespace std;

int n, m, c;

int main ()
{
	while (scanf ("%d %d %d", &n, &m, &c), n || m || c) {
		int ans;
		n-=7;
		m-=7;
		if (n&1 && m&1) {
			ans = (n*m)/2;
			if (c)
				ans++;
		}
		else
			ans = (n*m)/2;
		printf ("%d\n", ans);
	}

	return 0;
}
