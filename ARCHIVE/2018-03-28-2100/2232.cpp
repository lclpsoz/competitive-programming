#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n, x;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x);
		printf ("%d\n", (1 << x)-1);
	}
	return 0;
}
