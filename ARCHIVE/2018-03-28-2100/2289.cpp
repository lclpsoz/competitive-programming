#include <bits/stdc++.h>
using namespace std;

long long unsigned a, b, c;

int main ()
{
	while (scanf ("%llu %llu", &a, &b), a || b) {
		c = a ^ b;
		printf ("%d\n", __builtin_popcountll(c));
	}
	return 0;
}
