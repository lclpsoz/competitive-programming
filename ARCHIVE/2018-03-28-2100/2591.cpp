#include <cstdio>

int a1, a2;
char c;

int main ()
{
	c = getchar ();
	while (c != '\n')
		c = getchar ();

	c = getchar ();
	while (c != EOF) {
		a1 = a2 = 0;
		c = getchar ();
		while (c == 'a') {
			a1++;
			c = getchar ();
		}
		while (c != 'a')
			c = getchar ();
		while (c == 'a') {
			a2++;
			c = getchar ();
		}
		while (c != '\n')
			c = getchar ();
		putchar ('k');
		a1 *= a2;
		for (int i = 0; i < a1; i++)
			putchar ('a');
		putchar ('\n');
		c = getchar ();
	}

	return 0;
}
