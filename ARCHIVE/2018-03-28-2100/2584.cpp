#include <bits/stdc++.h>
using namespace std;

int n, a;
double ans[10010];

const double TG = tan ((54.0*M_PI)/180.0);

int main ()
{
	for (int i = 1; i < 10010; i++) {
		ans[i] = (((TG*(i/2.0))*i)/2.0)*5.0;
	}
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &a);
		printf ("%.3lf\n", ans[a]);
	}
	return 0;
}
