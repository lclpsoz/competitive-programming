#include <bits/stdc++.h>
using namespace std;

int arr[10];

int main ()
{
	arr[0] = arr[1] = 1;
	for (int i = 2; i <= 8; i++)
		arr[i] = arr[i-1]*i;

	int n;
	scanf ("%d", &n);
	int ans = 0;
	for (int i = 8; i >= 0 && n; i--) {
		while (n >= arr[i]) {
			ans++;
			n-=arr[i];
		}
	}
	printf ("%d\n", ans);

	return 0;
}
