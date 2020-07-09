#include <bits/stdc++.h>
using namespace std;

int n;
double x;
int total;

int main ()
{
	while (scanf ("%d", &n), n) {
		total = 0;
		int n1 = n;
		while (n--) {
			scanf ("%lf", &x);
			total += x*100;
		}
		total /= n1;
		printf ("%0.2lf\n", (double)total/100.0);
	}

	return 0;
}
