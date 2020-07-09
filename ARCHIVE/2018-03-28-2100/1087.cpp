#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;

int main () {

	while (scanf ("%d %d %d %d", &a, &b, &c, &d), a) {
		if (a == c && b == d)
			printf ("0\n");
		else if (a == c || b == d)
			printf ("1\n");
		else if (a+b == c+d)
			printf ("1\n");
		else if (a-b == c-d)
			printf ("1\n");
		else
			printf ("2\n");
	}
	return 0;
}
