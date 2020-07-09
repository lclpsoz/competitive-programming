#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

const int MAXN = 1e4;

int n;
int arr[MAXN];

int main ()
{
	scanf ("%d", &n);
	for (int i = 0; i < 2*n; i++)
		scanf ("%d", &arr[i]);

	sort (arr, arr+(2*n));
	int x1 = 0;
	for (int i = 0; i < n; i++)
		x1 = max (x1, arr[i]);
	int x2 = 1000000;
	for (int i = n; i < 2*n; i++)
		x2 = min (x2, arr[i]);
	bool test;
	if (x1 >= x2)
		test = false;
	else test = true;

	test ? printf ("YES\n") : printf ("NO\n");

	return 0;
}
