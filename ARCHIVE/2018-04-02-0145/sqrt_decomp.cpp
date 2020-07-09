#include <bits/stdc++.h>

const int MAXN = 1e6+100;
const int MAXSQ = 1e3+10;

int x, n;
int arr[MAXN];
int arr_sq[MAXSQ];

int main ()
{
	scanf ("%d", &n);
	int sq = sqrt (n);
	int ans;
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x);
		arr[i] = x;
		arr_sq[i/sq] += x;
	}
	for (int i = 0; i < n; i++)
		printf ("%d ", arr[i]);
	putchar ('\n');
	for (int i = 0; i < sq; i++)
		printf ("%d ", arr_sq[i]);
	putchar ('\n');
	while (1) {
		ans = 0;
		printf ("Entre com ranges: ");
		scanf ("%d %d", &i &f);
		while (i%sq && i <= f) {
			ans += arr[i];
			i++;
		}
		while (i+(sq-1) <= f) {
			ans += arr_sq[i/sq];
			i+=sq;
		}
		while (i <= f) {
			ans += arr[i];
			i++;
		}
	}
	return 0;
}
