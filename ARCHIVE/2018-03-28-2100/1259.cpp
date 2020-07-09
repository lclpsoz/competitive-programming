#include <bits/stdc++.h>
using namespace std;

vector<int> even, odd;

int main ()
{
	int n, x;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x);
		if (x%2)
			odd.push_back (x);
		else
			even.push_back (x);
	}
	sort (odd.begin(), odd.end(), greater<int>());
	sort (even.begin(), even.end());

	for (int i : even)
		printf ("%d\n", i);
	for (int i : odd)
		printf ("%d\n", i);

	return 0;
}
