#include <bits/stdc++.h>
using namespace std;

double arr[3];

int main ()
{
	for (int i = 0; i < 3; i++)
		scanf ("%lf", &arr[i]);
	if (arr[0] < arr[1] && arr[0] < arr[2])
		printf ("Otavio\n");
	else if (arr[1] < arr[0] && arr[1] < arr[2])
		printf ("Bruno\n");
	else if (arr[2] < arr[0] && arr[2] < arr[1])
		printf ("Ian\n");
	else
		printf ("Empate\n");
	return 0;
}
