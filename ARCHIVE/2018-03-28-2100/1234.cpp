#include <bits/stdc++.h>
using namespace std;

char c;
bool bef;

int main ()
{
	c = getchar ();
	while (c != EOF) {
		bef = true;
		while (c != '\n') {
			if (c > ' ') {
				if (bef && c >= 'a')
					c ^= 1<<5;
				else if (!bef && c < 'a')
					c ^= 1<<5;
				bef = !bef;
			}
			putchar (c);
			c = getchar ();
		}
		if (c != EOF)
			putchar ('\n');
		c = getchar();
	}

	return 0;
}
