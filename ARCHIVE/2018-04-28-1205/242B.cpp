#include <bits/stdc++.h>
using namespace std;

int n;
int a, b;
int x, y, pos;

int main ()
{
	pos = -1;
	scanf ("%d", &n);
	scanf ("%d %d", &x, &y);
	pos = 1;
	for (int i = 2; i <= n; i++) {
		// printf ("%d %d\n", x, y);
		scanf ("%d %d", &a, &b);
		if (x > a || y < b) {
			if (a <= x && b >= y) {
				x = a;
				y = b;
				pos = i;
			}
			else {
				x = min (x, a);
				y = max (y, b);
				pos = -1;
			}
		}
		else if (a <= x && b >= y) {
			x = a;
			y = b;
			pos = i;
		}
	}

	printf ("%d\n", pos);

	return 0;
}
