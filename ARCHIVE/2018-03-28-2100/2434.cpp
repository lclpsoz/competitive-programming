#include <bits/stdc++.h>
using namespace std;

int n, x, val, mini;

int main ()
{
	scanf ("%d %d", &n, &val);
	mini = val;
	for (int i=0; i < n; i++) {
		scanf ("%d", &x);
		val += x;
		mini = min (mini, val);
	}
	printf ("%d\n", mini);
	return 0;
}
