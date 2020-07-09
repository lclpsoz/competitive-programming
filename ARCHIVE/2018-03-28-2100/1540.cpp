#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned llu;

int i;
llu n, a, b, c, d, ans;

int main ()
{
	scanf ("%llu", &n);
	for (i = 0; i < n; i++) {
		scanf ("%llu %llu %llu %llu", &a, &b, &c, &d);
		ans = ((d-b)*100)/(c-a);
		printf ("%llu,%02llu\n", ans/100, ans%100);
	}
	return 0;
}
