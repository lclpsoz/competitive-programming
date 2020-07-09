#include <cstdio>

const int MAXN = 1e5+10;

int n, d, digit;
char str[MAXN];

int main ()
{
	while (scanf ("%d %d", &n, &d), n || d) {
		scanf ("%s", str);
		int d_a = d;
		digit = 0;
		while (d) {
			for (int i = 0; d && i < n; i++)
				if (str[i] == (digit+'0')) {
					str[i] = ' ';
					d--;
				}
			digit++;
		}
		for (int i = 0; i < n; i++)
			if (str[i] != ' ')
				putchar(str[i]);
		putchar('\n');
	}
	return 0;
}
