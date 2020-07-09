#include <bits/stdc++.h>
using namespace std;

int alpha (char c) {
	if (c >= 'a' && c <= 'z')
		return 1;
	if (c >= 'A' && c <= 'Z')
		return 2;
	return 0;
}

int main ()
{
	char c = getchar ();
	int aux;
	while (c != EOF) {
		if (alpha (c)) {
			aux = alpha (c);
			c = tolower (c);
			c -= 'a';
			c = (c+13)%('z'-'a'+1);
			if (aux == 2)
				c += 'A';
			else
				c += 'a';
		}
		putchar (c);
		c = getchar ();
	}
	return 0;
}
