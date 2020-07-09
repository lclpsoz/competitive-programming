#include <bits/stdc++.h>
using namespace std;

pair<double, int> arr[30];

int main ()
{
	int n;
	double a;
	int caso = 1;
	while (scanf ("%d", &n) != EOF) {
		for (int i = 0; i < 10; i++) {
			scanf ("%lf", &a);
			arr[i] = {-a, i};
		}
		sort (arr, arr+10);
		printf ("Caso %d: ", caso++);
		for (int i = 0; i < n; i++)
			printf ("%d", arr[i].second);
		putchar ('\n');
	}

	return 0;
}
