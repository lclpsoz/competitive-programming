#include <bits/stdc++.h>
using namespace std;

int x;

int main ()
{
	scanf ("%d", &x);
	int i = 0;
	while (x >= 2) {
		i++;
		x >>= 1;
	}
	int j = 1;
	while (i) {
		j *= 2;
		i--;
	}
	printf ("%d\n", j*j);
	return 0;
}
