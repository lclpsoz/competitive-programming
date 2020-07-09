#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+100;

int i;
int n, arr[MAXN], bef, a, b, big;

int main ()
{
	while (scanf ("%d", &n) != EOF) {
		scanf ("%d", &arr[0]);
		for (i = 1; i < n; i++) {
			scanf ("%d", &arr[i]);
			arr[i] += arr[i-1];
		}
		big = arr[n-1];
		bef = big-(2*arr[0]);
		i = 1;
		while (abs(big-(2*arr[i])) < bef)
			bef = abs(big-(2*arr[i++]));
		a = arr[i-1];
		b = big-a;
		if (a > b)
			swap (a, b);
		printf ("%d %d\n", a, b);
	}
	return 0;
}
