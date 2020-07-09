#include <bits/stdc++.h>
using namespace std;

int i;
int n, x, y;

int main ()
{
	scanf ("%d", &n);
	for (i = 0; i < n; i++) {
		scanf ("%d %d", &x, &y);
		printf ("%d\n", (x/3)*(y/3));
	}
	return 0;
}
