#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;

int n, m, size;
char str[MAXN], x, y;
map <char, char> dic;

int main ()
{
	scanf ("%d %d ", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf (" %c %c ", &x, &y);
		dic[x] = y;
		dic[y] = x;
	}
	for (int i = 0; i < m; i++) {
		if (i)
			getchar ();
		scanf ("%[^\n]", str);
		size = strlen (str);
		for (int j = 0; j < size; j++) {
			if (dic[str[j]] != '\0')
				str[j] = dic[str[j]];
			putchar (str[j]);
		}
		putchar ('\n');
	}

	return 0;
}
