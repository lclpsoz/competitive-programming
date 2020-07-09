#include <bits/stdc++.h>
using namespace std;

int n;
int arr[15];
double total;

int main ()
{
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &arr[i]);
		total += arr[i];
	}

	sort (arr, arr+n, greater<int>());

	if (arr[0] > 0.45*total)
		printf ("1\n");
	else if (arr[0] >= 0.4*total && (((0.1*total)+arr[1]) <= arr[0]))
		printf ("1\n");
	else
		printf ("2\n");

	return 0;
}
