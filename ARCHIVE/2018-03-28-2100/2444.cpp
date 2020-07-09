#include <bits/stdc++.h>
using namespace std;

int i;
int v, n, x;

int main ()
{
	scanf ("%d %d", &v, &n);
	for (i = 0; i < n; i++) {
		scanf ("%d", &x);
		v += x;
		if (v > 100)
			v = 100;
		else if (v < 0)
			v = 0;
	}
	printf ("%d\n", v);
	return 0;
}
