#include <bits/stdc++.h>
using namespace std;

int n;

void func (int x) {
	for (int i = x; i >= x-2; i--)
		printf (" %d", i);
}

int main ()
{
	scanf ("%d", &n);
	if (n == 2)
		printf ("3\n2 1 2\n");
	else if (n == 3)
		printf ("4\n2 1 3 2\n");
	else {
		printf ("%d\n", ((n/2)*3)+n%2);
		if (n&1) {
			printf ("2 1");
			for (int i = 4; i < n; i+=2)
				func (i);
			printf (" %d %d\n", n, n-1);
		} else {
			printf ("1");
			for (int i = 3; i < n; i+=2)
				func (i);
			printf (" %d %d\n", n, n-1);
		}
	}

	return 0;
}
