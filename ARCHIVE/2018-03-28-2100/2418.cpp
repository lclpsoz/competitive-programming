#include <bits/stdc++.h>
using namespace std;

int arr[5];
double x;

int main ()
{
	for (int i = 0; i < 5; i++) {
		scanf ("%lf", &x);
		arr[i] = round(10*x);
	}
	sort (arr, arr+5);
	double ans = 0;
	for (int i = 1; i < 4; i++)
		ans += arr[i];
	printf ("%.1lf\n", ans/10);
	return 0;
}
