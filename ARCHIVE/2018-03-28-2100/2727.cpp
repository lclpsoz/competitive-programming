#include <bits/stdc++.h>
using namespace std;

int i, j;
int n, n2;
int ans;
char arr[1000];

int main ()
{
	while (scanf ("%d", &n) != EOF) {
		for (i = 0; i < n; i++) {
			scanf (" %[^\n] ", arr);
			j = 0;
			while (arr[j] == '.') j++;
			ans = strlen (arr);
			switch (j) {
				case 1: ans /= 2;
						break;
				case 2: ans /= 3;
						break;
				case 3: ans /= 4;
						break;
			}
			ans *= 3;
			ans += j-1;

			putchar ('a'+ans);
			putchar ('\n');
		}


	}

	return 0;
}
