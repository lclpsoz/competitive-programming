#include <bits/stdc++.h>
using namespace std;

int n, x;
bool arr[1010];

int main ()
{
	scanf ("%d", &n);
	for (int i = 0; i < n-1; i++) {
		scanf ("%d", &x);
		arr[x] = true;
	}
	x = 0;
	for (int i = 1; i <= n && !x; i++)
		if (!arr[i])
			x = i;
	printf ("%d\n", x);
	return 0;
}
