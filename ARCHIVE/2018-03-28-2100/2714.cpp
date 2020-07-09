#include <bits/stdc++.h>
using namespace std;

int n;
char arr[110];

int main ()
{
	scanf ("%d", &n);
	int ans = true;
	while (n--) {
		ans = true;
		getchar (); // '\n'
		scanf ("%[^\n]", arr);
		if (strlen(arr) != 20 || arr[0] != 'R' || arr[1] != 'A')
			ans = false;
		else { // If it have invalid chars in number part
			for (int i = 2; ans && i < 20; i++)
				if (arr[i] < '0' || arr[i] > '9')
					ans = false;
		}
		if (ans) { // If there's a number
			ans = false;
			for (int i = 2; i < 20; i++)
				if (arr[i] != '0')
					ans = true;
		}
		if (ans) {
			int i = 2;
			for (; arr[i] == '0'; i++);
			while (i < 20)
				putchar (arr[i++]);
		}
		else
			printf ("INVALID DATA");

		putchar ('\n');
	}

	return 0;
}
