#include <bits/stdc++.h>
using namespace std;

char str[50];
int x;
long long tou, jeep;

int main ()
{
	while (scanf ("%s", str), str[0] != 'A') {
		scanf ("%d", &x);
		if (str[0] == 'S') {
			jeep++;
			tou += x;
		}
		else {
			jeep--;
			tou -= x;
		}
	}
	printf ("%lld\n%lld\n", tou, jeep);
	return 0;
}
