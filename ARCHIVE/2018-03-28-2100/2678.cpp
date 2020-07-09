#include <bits/stdc++.h>
using namespace std;

char str[400], c;

int main ()
{
	while (scanf ("\n%[^\n]", str) != EOF) {
		getchar (); //ignores \n
		for (int i = 0; i < strlen (str); i++) {
			c = tolower (str[i]);
			if (c >= '0' && c <= '9')
				putchar (c);
			else if (c == '*')
				putchar ('*');
			else if (c == '#')
				putchar ('#');
			else if (c >= 'a' && c <= 'z') {
				if (c < 'p') {
					c -= 'a';
					c = (c/3) + 2;
					putchar (c+'0');
				}
				else if (c < 't')
					putchar ('7');
				else if (c < 'w')
					putchar ('8');
				else
					putchar ('9');
			}
		}
		putchar ('\n');
	}
	return 0;
}
