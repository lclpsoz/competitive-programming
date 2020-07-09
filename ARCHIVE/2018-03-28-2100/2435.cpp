#include <bits/stdc++.h>
using namespace std;

double arr[2][4];

int main ()
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			scanf ("%lf", &arr[i][j]);

	if ((arr[0][2] / arr[0][1]) < (arr[1][2]/arr[1][1]))
		printf ("%.0lf\n", arr[1][0]);
	else
		printf ("%.0lf\n", arr[0][0]);
	return 0;
}
