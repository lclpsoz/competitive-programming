#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned llu;

llu n;
int t;

int main ()
{
	scanf ("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf ("%llu", &n);
		printf ("%llu\n", (((n)*(n+1))/2)+1);
	}
	return 0;
}
