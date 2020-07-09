#include <bits/stdc++.h>
using namespace std;

int n, aux1, aux2;
char str[200], c;

int main ()
{
	while (scanf (" %[^\n]", str) != EOF) {
		n = 0;
		for (int i = 0; i < strlen (str); i++) {
			c = tolower(str[i]);
			if (c >= 'a' && c <= 'z')
				n += ((c-'a') % 9) + 1;
		}
		while (n >= 10) {
			aux1 = n; aux2 = 0;
			while (aux1 > 0) {
				aux2 += aux1 % 10;
				aux1 /= 10;
			}
			n = aux2;
		}
		printf ("%d\n", n);
	}
	return 0;
}
