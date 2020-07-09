#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;

int n, m;
char c;
char str[MAXN];


int main ()
{
	while (scanf ("%d %d ", &n, &m), n || m) {
		c = getchar ();
		int i = 0;
		while (c != '\n') {
			while (i && m && c > str[i-1]) {
				m--;
				i--;
			}
			str[i++] = c;
			c = getchar ();
		}
		i -= m;
		str[i] = '\0';
		printf ("%s\n", str);
	}

	return 0;
}
