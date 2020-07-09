#include <bits/stdc++.h>
using namespace std;

int arr[5];

int main ()
{
	for (int i = 0; i < 4; i++)
		scanf ("%d", &arr[i]);
	sort (arr, arr+4);
	double a = (double)arr[1]/arr[0];
	double b = (double)arr[3]/arr[2];

	printf ("%c\n", a == b ? 'S' : 'N');

	return 0;
}
