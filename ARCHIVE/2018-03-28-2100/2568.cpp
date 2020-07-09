#include <bits/stdc++.h>
using namespace std;

int arr[5];

int main ()
{
	for (int i = 0; i < 4; i++)
		scanf ("%d", &arr[i]);
	if (arr[0] & 1)
		arr[3] & 1 ? printf ("%d\n", arr[1]+arr[2]) : printf ("%d\n", arr[1]);
	else
		arr[3] & 1 ? printf ("%d\n", arr[1]-arr[2]) : printf ("%d\n", arr[1]);
	return 0;
}
