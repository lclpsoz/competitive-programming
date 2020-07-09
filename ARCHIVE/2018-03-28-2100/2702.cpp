#include <bits/stdc++.h>
using namespace std;

int arr1[3], arr2[3];
int ans;

int main ()
{
	for (int i = 0; i < 3; i++)
		scanf ("%d", &arr1[i]);
	for (int i = 0; i < 3; i++)
		scanf ("%d", &arr2[i]);
	for (int i = 0; i < 3; i++)
		if (arr2[i] - arr1[i] > 0)
			ans += arr2[i] - arr1[i];
	printf ("%d\n", ans);

	return 0;
}
