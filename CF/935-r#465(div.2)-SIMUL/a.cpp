#include <bits/stdc++.h>
using namespace std;

int n;

int main ()
{
	scanf ("%d", &n);
	int ans = 1;
	for (int i = 2; i <= n/2; i++)
		if ((n-i)%i == 0)
			ans++;
	printf ("%d\n", ans);

	return 0;
}
