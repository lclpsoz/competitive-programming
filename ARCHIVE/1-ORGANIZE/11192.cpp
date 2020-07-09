#include <bits/stdc++.h>
using namespace std;

int n;
stack<char> pi;
char str[10000];

int main ()
{
	while (scanf ("%d", &n), n) {
		str[0] = '\0';
		scanf ("%s", str);
		n = strlen (str) / n;
		for (int i = 0; str[i] != '\0'; i++) {
			pi.push (str[i]);
			if ((i+1)%n == 0)
				while (!pi.empty ()) {
					putchar (pi.top());
					pi.pop ();
				}
		}
		putchar ('\n');
	}

	return 0;
}
