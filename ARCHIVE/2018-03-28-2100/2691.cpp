#include <bits/stdc++.h>
using namespace std;

int n, x, y;

int main ()
{
	scanf ("%d", &n);
	while (n--) {
		scanf ("%dx%d", &x, &y);
		for (int i = 5; i <= 10; i++) {
			if (x != y)
				printf ("%d x %d = %d && %d x %d = %d\n", x, i, x*i, y, i, y*i);
			else
				printf ("%d x %d = %d\n", x, i, x*i);
		}
	}

	return 0;
}
