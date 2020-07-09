#include <bits/stdc++.h>
using namespace std;

int n, m;

int main ()
{
	scanf ("%d %d", &n, &m);
	int bef, now;
	bool ans = true;
	scanf ("%d", &bef);
	for (int i = 1; i < n; i++) {
		scanf ("%d", &now);
		if (now-bef > m)
			ans = false;
		bef = now;
	}
	ans ? printf ("S\n") : printf ("N\n");

	return 0;
}
