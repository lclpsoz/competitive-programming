#include <bits/stdc++.h>
using namespace std;

void putSpaces (int n)
{
	for (int i = 0; i < n; i++)
		putchar (' ');
}

int main ()
{
	int n;
	while (scanf ("%d", &n) != EOF) {
		for (int i = n/2, j = 1; j <= n; i--, j+=2) {
			putSpaces (i);
			for (int k = 0; k < j; k++)
				putchar ('*');
			putchar ('\n');
		}
		putSpaces (n/2);
		putchar ('*');
		putchar ('\n');
		putSpaces ((n/2)-1);
		putchar ('*');
		putchar ('*');
		putchar ('*');
		putchar ('\n');
		putchar ('\n');
	}

	return 0;
}
