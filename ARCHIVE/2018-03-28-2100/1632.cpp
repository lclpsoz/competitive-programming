#include <bits/stdc++.h>
using namespace std;

int n;
char arr[25];

int main ()
{
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf (" %s", arr);
		int ans = 1;
		for (int j = 0; arr[j] != '\0'; j++) {
			switch (tolower (arr[j])) {
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 's': ans *= 3;
						  break;
				default: ans *= 2;
			}
		}
		printf ("%d\n", ans);
	}
	return 0;
}
