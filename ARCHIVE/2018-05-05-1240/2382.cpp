#include <bits/stdc++.h>
using namespace std;

double arr[5];

int main ()
{
	for (int i = 0; i < 3; i++) {
		scanf ("%lf", &arr[i]);
		arr[i] /= 2;
	}
	scanf ("%lf", &arr[3]);

	double aux = sqrt((arr[0]*arr[0])+(arr[1]*arr[1]));
	double aux2 = sqrt((aux*aux)+(arr[2]*arr[2]));

	printf ("%c\n", aux2 <= arr[3] ? 'S' : 'N');
	
	return 0;
}
