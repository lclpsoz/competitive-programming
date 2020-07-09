#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+10;

int i, j;
int n, m, x, maxi, sec;
int arr[MAXN], ans[MAXN];

int main ()
{
	while (scanf ("%d %d", &n, &m), n || m) {
		maxi = 0;
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				scanf ("%d", &x);
				arr[x]++;
				maxi = max (maxi, arr[x]);
			}
		}
		sec = 0;
		for (i = 0; i < MAXN; i++)
			if (arr[i] != maxi)
				sec = max (sec, arr[i]);
		for (i = 0, j = 0; i < MAXN; i++) {
			if (arr[i] == sec)
				ans[j++] = i;
			arr[i] = 0;
		}
		for (i = 0; i < j; i++)
			printf ("%d ", ans[i]);
		putchar ('\n');
	}

	return 0;
}
