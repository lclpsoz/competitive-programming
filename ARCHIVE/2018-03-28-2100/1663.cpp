#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;

int n;
int arr[MAXN];
bool ans;
int main ()
{
	while (scanf ("%d", &n), n) {
		for (int i = 1; i <= n; i++)
			scanf ("%d", &arr[i]);
		ans = true;
		for (int i = 1; i <= n && ans; i++)
			if (arr[arr[i]] != i)
				ans = false;
		ans ? printf ("ambiguous\n") : printf ("not ambiguous\n");
	}
	return 0;
}
