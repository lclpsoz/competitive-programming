#include <bits/stdc++.h>
using namespace std;

int n;
long long c, p;
char ch;

int main ()
{
	scanf ("%d", &n);
	while (n--) {
		getchar (); // '\n'
		p = 0;
		int i = 0;
		while (ch = getchar (), ch != ' ')
			p |= (long long)(ch=='O') << i++;
		int s = i;
		scanf ("%lld", &c);
		p += c;
		for (i = 0; i < s; i++)
			(p & 1LL << i) ? putchar ('O') : putchar ('X');
		putchar ('\n');
	}

	return 0;
}
