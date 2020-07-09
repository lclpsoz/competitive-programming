#include <bits/stdc++.h>
using namespace std;

int n;

bool check (int x)
{
	int aux = 0;
	int r = x;
	while (x) {
		r += x%10;
		x/=10;
	}
	return n == r;
}

vector<int> ans;

int main ()
{
	scanf ("%d", &n);
	for (int i = max (1, n-100); i < n; i++) {
		if (check (i))
			ans.push_back (i);
	}
	printf ("%ld\n", ans.size());
	sort (ans.begin(), ans.end());
	for (int x : ans)
		printf ("%d\n", x);

	return 0;
}
