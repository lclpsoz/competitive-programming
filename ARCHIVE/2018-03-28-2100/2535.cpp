#include <bits/stdc++.h>
using namespace std;

int n, ans;
char str[150], c[3], *aux;

int main ()
{
	while (scanf ("%d", &n) != EOF) {
		ans = 0;
		for (int i = 0; i < n; i++) {
			scanf (" %[^\n]", str);
			if (strcmp (str, "cachorro") == 0) {
				scanf (" %[^\n]", str);
				c[0] = ' ';
				c[1] = str[0];
				c[2] = '\0';
				scanf (" %[^\n]", str);
				if ((strstr (str, " ") && str[0] == c[1] || strstr (str, c) != NULL))
					ans++;
			}
			else {
				scanf (" %[^\n]", str);
				scanf (" %[^\n]", str);
			}
		}
		printf ("%d\n", ans);
	}
	return 0;
}
