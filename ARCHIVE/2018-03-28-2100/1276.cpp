#include <bits/stdc++.h>
using namespace std;

char a, b;
bool arr[55];
char c;

int main ()
{
	c = getchar ();
	while (c != EOF) {
		while (c != '\n' && c != EOF) {
			arr[c-'a'] = true;
			c = getchar ();
		}
		c = getchar ();

		a = '\0';
		bool t = false;
		for (int i = 0; i < 29; i++) {
			// printf ("\t%d\n", arr[i]);
			if (arr[i] && a == '\0')
				a = i+'a';
			if (!arr[i] && a != '\0') {
				if (t) {
					putchar (',');
					putchar (' ');
				}
				t = true;
				putchar (a);
				putchar (':');
				putchar (i-1+'a');
				a = '\0';
			}
			arr[i] = false;
		}
		putchar ('\n');
	}

	return 0;
}
