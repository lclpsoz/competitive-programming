#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

int n;
long long arr[150];
long long aux[150];

bool func (int p)
{
	bool test = false;
	if (p == 0) {
		for (int i = 0; !test && i < n; i++) {
			long long x = arr[i];
			aux[p] = arr[i];
			arr[i] = -1;
			test = func (p+1);
			arr[i] = x;
		}
		return test;
	}
	else if (p < n) {
		for (int i = 0; !test && i < n; i++) {
			// printf ("%lld %lld\n", arr[i], aux[p-1]);
			if (arr[i]*2 == aux[p-1] || arr[i] == aux[p-1]*3) {
				long long x = arr[i];
				aux[p] = arr[i];
				arr[i] = -1;
				test = func (p+1);
				arr[i] = x;
			}
		}
		return test;
	}
	else if (p == n) {
		// printf ("%lld %lld\n", aux[p-1], aux[p-2]);
		if (aux[p-1]*2 == aux[p-2] || aux[p-1] == aux[p-2]*3)
			return true;
		else
			return false;
	}
}

int main ()
{
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf ("%lld", &arr[i]);

	func (0);
	for (int i = n-1; i >= 0; i--)
		printf ("%lld ", aux[i]);
	putchar ('\n');

	return 0;
}
