#include <bits/stdc++.h>
using namespace std;

int x, maxi;

int main ()
{
	maxi = 0;
	while (scanf ("%d", &x), x)
		maxi = max (maxi, x);
	cout << maxi << '\n';
	return 0;
}
