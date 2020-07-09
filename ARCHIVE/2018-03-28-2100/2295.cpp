#include <bits/stdc++.h>
using namespace std;

double arr[4];

int main ()
{
	for (int i = 0; i < 4; i++)
		scanf ("%lf", &arr[i]);

	if (arr[2]/arr[0] > arr[3]/arr[1])
		printf ("A\n");
	else
		printf ("G\n");
	return 0;
}
