#include <bits/stdc++.h>
using namespace std;

char str[250];
char ans[] = {'W', 'H', 'Q', 'E', 'S', 'T', 'X'}, c, answer, aux;

int main ()
{
	c = getchar();
	while (c != '*') {
		answer = 0;
		while (c != '\n') {
			aux = 0;
			while (c != '/') {
				int i = 0;
				for (; i < 7 && ans[i] != c; i++);
				aux += 1 << (6-i);
				c = getchar();
			}
			if (aux == (1 << 6))
				answer++;
			c = getchar();
		}
		printf ("%d\n", answer);
		c = getchar();
	}

	return 0;
}
