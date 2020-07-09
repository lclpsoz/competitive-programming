#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned llu;

int t;
llu n, r;

int main ()
{
	scanf ("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf ("%llu", &n);
		r = (llu) sqrt (2*n);
		while (((r*(r+1))/2) > n)
			r--;

		printf ("%llu\n", r);
	}

	return 0;
}
