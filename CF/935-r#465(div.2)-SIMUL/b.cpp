#include <bits/stdc++.h>
using namespace std;

int n;
char c;

int main ()
{
	scanf ("%d ", &n);
	int state = 0; // NEUTRAL
	int x, y;
	x = y = 0;
	int ans = 0;
	while (n--) {
		c = getchar ();
		if (c == 'U')
			y++;
		else
			x++;
		if (state == 0) {
			if (x > y)
				state = -1;
			else
				state = 1;
		} else if (state == 1 && x > y) {
			state = -1;
			ans++;
		} else if (state == -1 && x < y) {
			state = 1;
			ans++;
		}
	}
	printf ("%d\n", ans);

	return 0;
}
