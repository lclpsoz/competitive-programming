#include <bits/stdc++.h>
using namespace std;

int n;
set<string> conjunto;

int main ()
{
	scanf ("%d ", &n);
	char c;
	string str;
	char arr[50];
	for (int i = 0; i < n; i++) {
		str = "";
		c = '\0';
		conjunto.clear ();
		int k = 0;
		while (c != '\n') {
			str = "";
			c = getchar ();
			k = 0;
			while (c != ' ' && c != '\n') {
				arr[k++] = c;
				c = getchar ();
			}
			arr[k] = '\0';
			str = arr;
			if (str != "")
				conjunto.insert (str);
		}
		int j = 1;
		for (string str : conjunto) {
			for (char z : str)
				putchar (z);
			if (j < conjunto.size())
				putchar (' ');
			j++;
		}
		putchar ('\n');
	}
	return 0;
}
