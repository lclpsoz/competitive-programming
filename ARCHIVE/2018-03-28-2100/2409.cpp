#include <bits/stdc++.h>
using namespace std;

int arr[3], arr2[2];

int main ()
{
	for (int i = 0; i < 3; i++)
		scanf ("%d", &arr[i]);
	for (int i = 0; i < 2; i++)
		scanf ("%d", &arr2[i]);
	sort (arr, arr+3);
	sort (arr2, arr2+2);
	if (arr[0] <= arr2[0] && arr[1] <= arr2[1])
		printf ("S\n");
	else
		printf ("N\n");
	return 0;
}
