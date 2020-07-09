#include <bits/stdc++.h>
using namespace std;

int t, n;
char str[15];
bool check[15];
char aux[15];
int pos = 0;

void dfs (int v)
{
	if (pos == n) {
		for (int i = 0; aux[i] != '\0'; i++)
			putchar (aux[i]);
		putchar ('\n');
	} else {
		int lst = '-';
		for (int i = 0; i < n; i++) {
			if (!check[i]) {
				if (i && lst == str[i]) continue;
				lst = str[i];
				check[i] = true;
				aux[pos++] = str[i];
				dfs (i);
				pos--;
				check[i] = false;
			}
		}
	}
}

int main ()
{
	scanf ("%d", &t);
	while (t--) {
		scanf ("%s", str);
		n = strlen (str);
		sort (str, str+n);
		char lst = '-';
		aux[n] = '\0';
		for (int i = 0; i < n; i++) {
			if (i && lst == str[i])
				continue;
			lst = str[i];
			check[i] = true;
			aux[pos++] = str[i];
			dfs (i);
			pos--;
			check[i] = false;
		}
		putchar ('\n');
	}

	return 0;
}
