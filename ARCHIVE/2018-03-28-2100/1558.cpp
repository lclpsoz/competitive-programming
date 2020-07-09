#include <bits/stdc++.h>
using namespace std;

int i, j, x;
bool ans[10010];

int main ()
{
	for (i = 0; i <= 100; i++) {
		x = 0;
		for (j = 0; j <= 100 && x <= 10000; j++) {
			x = (i*i) + (j*j);
			if (x <= 10000)
				ans[x] = true;
		}
	}
	while (scanf ("%d", &x) != EOF) {
		if (x >= 0)
			ans[x] ? printf ("YES\n") : printf ("NO\n");
		else
			printf ("NO\n");
	}

	return 0;
}
