#include <bits/stdc++.h>
using namespace std;

int n, k;
int x;

int main ()
{
	scanf ("%d %d", &n, &k);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x);
		if ((5-x) >= k)
			ans++;
	}
	printf ("%d\n", ans/3);

	return 0;
}
