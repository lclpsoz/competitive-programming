#include <bits/stdc++.h>
using namespace std;

int n, x1, x2;

int main ()
{
	scanf ("%d", &n);
	while (n--) {
		scanf ("%dx%d", &x1, &x2);
		for (int i = 5; i <= 10; i++) {
			printf ("%d x %d = %d", x1, i, x1*i);
			if (x1 != x2)
				printf (" && %d x %d = %d", x2, i, x2*i);
			putchar ('\n');
		}
	}

	return 0;
}
