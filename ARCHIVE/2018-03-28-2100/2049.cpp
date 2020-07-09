#include <bits/stdc++.h>
using namespace std;

char sig[15], c;
int i = 0;
int ans = false;

int main ()
{
	int ins = 1;
	while (scanf (" %s ", sig), !(sig[0] == '0' && sig[1] == '\0')) {
		if (ins > 1)
			putchar ('\n');
		ans = false;
		i = 0;
		while (c = getchar(), c != '\n') {
			// printf ("%c", c);
			if (!ans) {
				if (sig[i] == c) {
					i++;
					if (sig[i] == '\0')
						ans = true;
				}
				else
					i = 0;
			}
		}
		// putchar ('\n');
		printf ("Instancia %d\n", ins++);
		ans ? printf ("verdadeira") : printf ("falsa");
		putchar ('\n');
	}

	return 0;
}
