#include <bits/stdc++.h>
using namespace std;

int n, x;
int arr[110];

int main ()
{
	while (scanf ("%d", &n), n) {
		for (int i = 0; i < n; i++) {
			scanf ("%d", &x);
			arr[x]++;
		}
		int i;
		for (i = 1; i < 101; i++)
			if (arr[i]) {
				printf ("%d", i);
				arr[i]--;
				break;
			}
		int j;
		if (n > 1) {
			for (j = i; j < 101; j++)
				while (arr[j]) {
					printf (" %d", j);
					arr[j]--;
				}

		}
		putchar ('\n');
		for (i = 0; i < 101; i++)
			arr[i] = 0;

	}
	return 0;
}
