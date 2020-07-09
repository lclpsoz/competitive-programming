#include <bits/stdc++.h>
using namespace std;

int n;
char arr[120];

int main ()
{
	scanf ("%d ", &n);
	while (n--) {
		char c = ' ';
		while (c != '\n') {
			scanf ("%[^\n ]", arr);
			if (strstr (arr, "oulupukk")) {
				arr[0] = 'J'; arr[9] = 'i';
			}
			printf ("%s", arr);
			arr[0] = '\0';
			c = getchar ();
			putchar (c);
		}
	}

	return 0;
}
