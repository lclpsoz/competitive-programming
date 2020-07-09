#include <bits/stdc++.h>
using namespace std;

int y, k, n;

int main ()
{
	scanf ("%d %d %d", &y, &k, &n);
	int st = ((y/k)+1)*k;
	int i = st;
	bool test = true;
	if (i <= n) {
		printf ("%d", i-y);
		i+=k;
	}
	else
		test = false;
	while (i <= n) {
		printf (" %d", i-y);
		i+=k;
	}
	if (!test)
		printf ("-1");
	putchar ('\n');

	return 0;
}
