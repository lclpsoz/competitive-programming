#include <bits/stdc++.h>
using namespace std;

int n, m;
char str1[110], str2[110];

int main ()
{
	scanf ("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		scanf ("%[^\n]", str1);
		getchar ();
		scanf ("%[^\n]", str2);
		getchar ();
		m = strlen(str1);
		for (int j = 0; j < m; j+=2) {
			putchar(str1[j]);
			putchar(str1[j+1]);
			putchar(str2[j]);
			if (strlen(str2) > j+1)
				putchar(str2[j+1]);
		}
		putchar ('\n');
	}
	return 0;
}
